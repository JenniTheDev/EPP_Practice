#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



double findAverageScore(int numberJudges, int judgeScores[]);


int main(){

int numberJudges = 0;
int *judgeScores;
int contestantNumber;
vector < pair<double, int> > finalScores ; 

cout << "Enter the Number of Judges." << endl;
cin >> numberJudges ;


//this is what needs to loop until the negative number is given
do {
    cout <<"Enter Contestant Number" << endl;
    cin >> contestantNumber;

    if (contestantNumber > 0){

        judgeScores = new int [numberJudges];

        for (int i = 0; i < numberJudges; i++){
            cout << "Enter score " << endl;
            cin >> judgeScores[i];
        }  

    double contestantAverage = findAverageScore(numberJudges, judgeScores);

    finalScores.push_back(make_pair(contestantAverage, contestantNumber));

    cout << "Contestant Number " << contestantNumber << " Average Score " << contestantAverage << endl;

    }

} while (contestantNumber > 0);


sort (finalScores.begin(), finalScores.end());
cout << "Highest Score is Contestant " << finalScores.back().second << " with a " << finalScores.back().first << endl; 


}


double findAverageScore(int numberJudges, int judgeScores[]){
    
    int tempLow = judgeScores[0];

    for (int i = 1; i < numberJudges; i++){
        if  ( tempLow > judgeScores[i] ) {
            tempLow = judgeScores[i];
        }
    }

    int tempHigh = judgeScores[0];

    for (int i = 1; i < numberJudges; i++){
        if  ( tempHigh < judgeScores[i] ) {
            tempHigh = judgeScores[i];
        }
    }


    for (int i = 0; i < numberJudges; i++){
        if (tempLow == judgeScores[i]){
            judgeScores[i] = 0;
            break;
        }
    }

    for (int i = 0; i < numberJudges; i++){
        if (tempHigh == judgeScores[i]){
            judgeScores[i] = 0;
            break;
        }
    }

    int total = 0;

    for (int i = 0; i < numberJudges; i++ ){
        total += judgeScores[i];
        
    }

    //Needs to return decimals so I need to divide an int by a double?
    double judgesMinusTwo = numberJudges - 2;

    double average = total / judgesMinusTwo;
    cout << "average" << average << endl;
    return average;
}

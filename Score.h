#ifndef P47_SCORE_H

#define P47_SCORE_H





#include <iostream>

#include <fstream>

#include <string>





class Score{

private: 

    static inline long int currentScore;

    long int scoreCap = 9999;

public:

    Score();



    long int GetScore();



    void AddScore(int addedScore);



    void SetScore(long int newScore);



    std::string FetchScores();



    void WriteNewHighScore(std::string Name, long int newHighScore);

};



#endif

#ifndef P47_SCORE_H

#define P47_SCORE_H





#include <iostream>

#include <fstream>

#include <string>





class Score{

private: 
// score at the current game. nullijfied at the beginning of a new game session. can be saved at the end of a session
    static inline long int currentScore; 

    // cap that score can not go over. needed to prevent out-of-memory errors.
    long int scoreCap = 9999;

public:

    Score(); // default constructor. loads information from a file


// returns current score
    long int GetScore();

// increases the current score by the value passed to it
    void AddScore(int addedScore);

// sets the current score to a passed value
    void SetScore(long int newScore);

// returns scores from the data-saving file
    std::string FetchScores();

// writes a new highscore in the data-saving file ( only keeps the top 5 )
    void WriteNewHighScore(std::string Name, long int newHighScore);

};


#endif

//

// Created by winni on 9/10/2024.

//



#include "Score.h"

#include "fstream"

#include <vector>



Score::Score() {

    currentScore = 0;

}



long int Score::GetScore() {

    return currentScore;

}



void Score::SetScore(long newScore) {

    if (newScore > scoreCap)

    {

        currentScore = scoreCap;

    } else {

        currentScore = newScore;

    }

}



void Score::AddScore(int addedScore) {

    if (currentScore + addedScore > scoreCap)

    {

        currentScore = scoreCap;

    } else {

        currentScore += addedScore;

    }

}



std::string Score::FetchScores() {

    std::string output;

    int i = 0;

    std::fstream scoreFile;

    scoreFile.open("score.txt");

    while (scoreFile.is_open())

    {

        std::string line;

        

        while (getline(scoreFile, line))

        {

            output += line;

            output += "\n";

        }

        scoreFile.close();

    }

    

    return output;

}



void Score::WriteNewHighScore(std::string Name, long int newHighScore) {

    std::string scores = Score::FetchScores();

    std::vector<std::string> scoresArray;

    std::string newScore = Name;

    int space;

    int newScoreIndex = -1;

    newScore += " ";

    newScore += std::to_string(newHighScore);

    for (int i = 0; i < 5; i++)

    {

        space = scores.find_first_of("\n");

        std::string score = scores.substr(0, space);

        scores.erase(0, space+1);

        scoresArray.push_back(score);

    }

    for (int i = 4; i >= 0; i--)

    {

        space = scoresArray[i].find(" ");

        int scoreNum = std::stoi(scoresArray[i].substr(space));

        if (newHighScore > scoreNum)

        {

            newScoreIndex = i;

        }

        

    }

    if (newScoreIndex != -1)

    {

        scoresArray.insert(scoresArray.begin() + newScoreIndex, newScore);

        scoresArray.pop_back();

        std::ofstream scoreFile;



        // for (size_t i = 0; i < 5; i++)

        // {

        //     std::cout << scoresArray[i] << std::endl;

        // }

        

        scoreFile.open("score.txt", std::ofstream::out | std::ofstream::trunc);

        

        while (scoreFile.is_open())

        {



            for (int i = 0; i < 5; i++)

            {

                scoreFile << scoresArray[i] << "\n";

                std::cout << scoresArray[i] << "\n";

            }

            scoreFile.close();

        }

        

    }



}

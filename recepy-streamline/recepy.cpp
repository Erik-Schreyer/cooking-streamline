#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

#include "recepy.h"

std::regex timer_reg_hours("([0-9]):([0-5][0-9])h");
std::regex timer_reg_minutes("([0-5][0-9]):?([0-5][0-9])?(?:min|Min)");

/** @brief constructor given vectors */
 Recepy::Recepy(const Recepy &copy) :
          name_(copy.name_),
          cookingtime_(copy.cookingtime_),
          ingredients_(copy.ingredients_),
          steps_(copy.steps_),
          timers_(copy.timers_),
          stepcount_(0)
        {

        }

/** @brief constructor given file */
 Recepy::Recepy(std::string recepytxt): stepcount_(0) {
          std::stringstream inputf(recepytxt);


          //The first line in the recepy file is the name
          std::string name;
          std::getline(inputf,name);
          name_ = name;

          //The second line contains the total cooking time
          std::smatch match;
          int cookingtime;

          std::string totaltimeline;
          std::getline(inputf,totaltimeline);
          if(std::regex_search(totaltimeline,match,timer_reg_hours)){
              cookingtime = 3600*std::stoi(match.str(1))+60*std::stoi(match.str(2));
          }
          if(std::regex_search(totaltimeline,match,timer_reg_minutes)){
              cookingtime = 60*std::stoi(match.str(1))+std::stoi(match.str(2));
          }
          cookingtime_=cookingtime;

          //A newline seperated list of ingredients
          std::string current_ingredient="";
          std::vector<std::string> ingredients;
          while(std::getline(inputf,current_ingredient)){
              if(current_ingredient=="Steps:"){break;}
              ingredients.push_back(current_ingredient);
          }

          ingredients_=ingredients;

          //The rest contains the steps of the recepy
          std::vector<std::string> steps;
          std::vector<std::vector<int>> timers;

          std::string current_step;


          int current_timer;
          int stepcount=0;
          while(std::getline(inputf,current_step)){
            stepcount++;
            steps.push_back(current_step);

            while(std::regex_search(current_step,match,timer_reg_hours)){
                current_timer = 3600*std::stoi(match.str(1))+60*std::stoi(match.str(2));
                timers[stepcount].push_back(current_timer);
            }
            while(std::regex_search(current_step,match,timer_reg_minutes)){
                current_timer = 60*std::stoi(match.str(1))+std::stoi(match.str(2));
                timers[stepcount].push_back(current_timer);
            }

          }
          steps_=steps;
          timers_=timers;
        }

/** @brief add recepy to specified cookbook folder as text file with .recepy ending */
 void Recepy::add_to_cook_book(std::string cookbook){
     std::ofstream output(cookbook+this->name_+".recepy");

     unsigned int i;
     output << name_ << '\n';
     output << "Total time: " << cookingtime_ << '\n';

     for(i=0; i<this->ingredients_.size() ;i++){
         output << ingredients_[i]<<'\n';
     }

     for(i=0; i<this->steps_.size() ;i++){
         output << steps_[i]<<'\n';
     }
     return;
 }


/** @brief load new recepy from sourcefile */
 Recepy* new_recepy(std::string inputf){
     std::ifstream input(inputf);

     std::stringstream buffer;
     buffer << input.rdbuf();
     std::string recepy = buffer.str();

     Recepy * result = new Recepy(recepy);

     return result;
 }

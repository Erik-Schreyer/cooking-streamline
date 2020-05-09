#ifndef RECEPY_H
#define RECEPY_H
#include <vector>
#include <string>

class Recepy {

private:

    std::string name_;

    int cookingtime_; //in seconds

    std::vector<std::string> ingredients_;
    std::string ingredientString_;
    std::vector<std::string> steps_;
    std::vector<std::vector<int>> timers_;

    int stepcount_; //starting at 0


public:
    /** @brief Empty Constructor**/
    Recepy();

    /** @brief Constructor using recepy string **/
    Recepy(std::string);

    /** @brief Copy Constructor **/
    Recepy(const Recepy &copy);


    /** @brief Destructor**/
    ~Recepy();

private:
    void string_to_vectors(std::string);

    void add_to_cook_book(std::string cookbook);

    //Getters
public:
    std::string getIngredientString(){
        return ingredientString_;
    }

    std::string getName(){
        return name_;
    }

    std::vector<std::string> getSteps(){
        return steps_;
    }

    std::string getStepAtStep(int step){
        return steps_[step];
    }

    std::vector<std::vector<int>> getTimers(){
        return timers_;
    }

    std::vector<int> getTimersAtStep(int step){
        return timers_[step];
    }

    int getStepcount(){
        return stepcount_;
    }

    void incStepcount(){
        stepcount_++;
        return;
    }

    void decStepcount(){
        stepcount_--;
        return;
    }

};

Recepy * new_recepy(std::string inputf);

#endif // RECEPY_H

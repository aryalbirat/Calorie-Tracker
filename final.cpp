#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
// #include <xlsxwriter.h>

using namespace std;

class User
{
protected:
    char userName[50];
    char exerciseDate[50];

public:
    void getUserInfo()
    {
        cout << "Enter your name: ";
        cin.getline(userName, 50);
        cout << "Enter the exercise date (mm-dd): ";
        cin.getline(exerciseDate, 50);
    }

    string getUserName()
    {
        return userName;
    }

    string getExerciseDate()
    {
        return exerciseDate;
    }
};

class Exercise : public User
{
protected:
    double caloriesBurnedPerMinute;
    char exerciseName[50];

public:
    Exercise() {}
    Exercise(const char n[50], double caloriesBurnedPerMinute)
    {
        strcpy(exerciseName, n);
        this->caloriesBurnedPerMinute = caloriesBurnedPerMinute;
    }
    string getExerciseName()
    {
        return exerciseName;
    }

    double calculateCaloriesBurned(int minutes)
    {
        return minutes * caloriesBurnedPerMinute;
    }
};

class Intensity : public Exercise
{
protected:
    int intensityLevel;

public:
    Intensity() {}
    Intensity(int intensitylevel, const char exerciseName[50], double caloriesBurnedPerMinute)
        : Exercise(exerciseName, caloriesBurnedPerMinute)
    {
        this->intensityLevel = intensitylevel;
    }

    int getIntesityInfo()
    {
        return intensityLevel;
    }
};

int main()
{
    Exercise running("Running", 10.0);
    Exercise swimming("Swimming", 8.0);
    Exercise cycling("Cycling", 7.0);

    Intensity a;
    a.getUserInfo();

    int minutes;
    cout << "ENTER THE TIMINGS (IN MINUTE)" << endl;

    cout << "Enter the number of minutes you ran: ";
    cin >> minutes;
    cin.ignore();
    double caloriesBurnedRunning = running.calculateCaloriesBurned(minutes);

    cout << "Enter the number of minutes you swam: ";
    cin >> minutes;
    cin.ignore();
    double caloriesBurnedSwimming = swimming.calculateCaloriesBurned(minutes);

    cout << "Enter the number of minutes you cycled: ";
    cin >> minutes;
    cin.ignore();
    double caloriesBurnedCycling = cycling.calculateCaloriesBurned(minutes);

    cout << "Enter the number of minutes you spent weight lifting: ";
    cin >> minutes;
    cin.ignore();

    int weightLiftingIntensity;
    cout << "Enter the intensity level for weight lifting(1-5): ";
    cin >> weightLiftingIntensity;
    cin.ignore();

    double weightliftingCaloriesPerMinute = 0.0;
    switch (weightLiftingIntensity)
    {
    case 1:
        weightliftingCaloriesPerMinute = 5.0;
        break;
    case 2:
        weightliftingCaloriesPerMinute = 7.0;
        break;
    case 3:
        weightliftingCaloriesPerMinute = 11.0;
        break;
    case 4:
        weightliftingCaloriesPerMinute = 13.0;
        break;
    default:
        weightliftingCaloriesPerMinute = 17.0;
        break;
    }

    Intensity highIntensity(weightLiftingIntensity, "Weightlifting", weightliftingCaloriesPerMinute);

    double caloriesBurnedWeightlifting = highIntensity.calculateCaloriesBurned(minutes);

    double totalCaloriesBurned = caloriesBurnedRunning + caloriesBurnedSwimming + caloriesBurnedCycling + caloriesBurnedWeightlifting;
    cout << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    cout << "Total calories burned: " << totalCaloriesBurned << " calories." << endl;
    cout << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    getch();
    return 0;
}

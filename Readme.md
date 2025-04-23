# Calorie Tracker

A C++ application that helps you monitor calories burned during various exercises with customizable intensity levels.

## Features

- **Track Multiple Exercise Types**
  - Running (10.0 cal/min)
  - Swimming (8.0 cal/min)
  - Cycling (7.0 cal/min)
  - Weightlifting (5.0-17.0 cal/min based on intensity)

- **Intensity Customization**
  - 5 weightlifting intensity levels
  - Progressive calorie burn rates (5.0-17.0 calories/min)

- **Personal Data Management**
  - User name tracking
  - Exercise date recording
  - Comprehensive calorie calculation

## How to Use

1. Enter your name and workout date
2. Input duration for each activity in minutes
3. Specify weightlifting intensity (1-5)
4. View your total calories burned

## Technical Implementation

- Object-oriented C++ with inheritance hierarchy
- User → Exercise → Intensity class structure
- Simple console interface for data input/output

## Getting Started

```
g++ final.cpp -o calorie_tracker
./calorie_tracker

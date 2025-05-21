# StudentCourseManager
Programming Fundamentals II – College Assignment

Project Overview - This C++ program was created to simulate a course enrollment system. This system allows for a user to manage
a catalog of courses and student enrollments. This was created while at UHV for Programming Fundamentals II. It demonstrates a 
practical use of dynamic memory allocation, file handling, and data structures to build a menu-driven console application.

Objectives of the program - Load course data from external files and allow the management of this data. This program allows 
interactive enrollment of courses, as well as dropping and cancellation of courses/students. Manages the course roster by utilizing
dynamic arrays and vectors and applies core object-oriented and procedural programming principles in C++.

Features of the program - 
  * Populates each course roster from data in the file "courseInfo.txt".
  * Interactive Menu Options : * Cancel a course ( Clears course info and marks it as reusable ).
                               * Drop a student ( Removes the students name from the roster ).
                               * Enroll a student ( Fills the first available vacancy ).
                               * Add a course ( Reuses a canceled course slots if available ).
                               * Display course info ( Lists all active courses and enrolled students ).
                               * List student courses - ( Finds all courses a student is enrolled in ).
                               * Exit.
Files -
  * Main source code : programming_Assignment2.cpp
  * Input files containing the courses which is required to run the program : coureInfo.txt
  * One file per course listing enrolled students : <rosterFileName>.txt

How to run - 
  * Ensure "couseInfo.txt" exists in the same directory.
  * Ensure the referenced roster files are present.
  * Compile with a C++ compiler.

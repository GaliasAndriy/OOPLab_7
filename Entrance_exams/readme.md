Interaction between classes:
    1. Connections between objects in programming
    2. Composition of objects. Implementation of compositions. Composition and subclasses.
    3. Aggregation. Composition and aggregation.
    4. Association. Dependencies.

Plan:
1. Classes and ierarchy:
    - class Client (make requests to the server side - queries)
    - class Server (run specific code referring on query and return response back to the client)

    - class Person: { // Base class for Applicant/Lecturer
        id,
        firstName,
        lastName,
        middleName, 
        age
    }

    Notice: The applicant register on Faculty and pass the entrance exams

    - class BaseFaculty { // Base for different Faculties
        math_coef,
        ukr_coef,
        history_coef
    }

    Notice: Other Faculties inherit a different faculty with an optional subject. Each faculty has its own coefficient for each subject.
    For now we will create 3 faculties

    - class ComputerScience : public BaseFaculty {
        // List of lecturer on Faculty 
    }
    - class HistoricalFaculty : public BaseFaculty {
        // List of lecturer on Faculty
    } 
    etc...

    - class Applicant : public Person, public *SomeFaculty* {
        phone_number,
        email,
        math_points,
        urkainian_points,
        history_pointst
    }

    Notice: Lecturer assess applicant 

    - class Lecturer : public Person, public Applicant {
        title, // Assistant, Assistant Professor etc.
        exam_grade // avg rate 
    }

    // In the last order, we'll get info about lecturer, which inherit applicant info and assess applicant. Then we compare exam_grade with addmision_score and if exam_grade >= addmision_score, applicant enters the faculty. We'll create two .txt files for passed and failed applicants with all data

2. Constructors/destructor/abstract or virtual methods/non-virtual methods
3. Getter/setter
4. Methods that will interact with objects
5. Text files as a type of database, in which we'll store information. In this files it should be more or equal than 10 records
6. Create console menu
7. Develop a program that simulates the operation of an automated system, which will demonstrate the access of client objects to the server object of the OS.






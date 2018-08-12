/*
 * Section.cpp
 *
 *  Created on: May 22, 2018
 *      Author: Xinmeng Zhang
 */

#include "Section.h"
#include "Department.h"
#include "Person.h"
#include "Course.h"

namespace CS_5004 {

/**
 * Create a section of a course with a given capacity.
 *
 * @param teacher the teacher for the section
 * @param course the course
 * @param sectionNo the section number
 * @param capacity  the section capacity
 */
Section::Section(Person* teacher, Course* course, unsigned int sectionNum, unsigned int capacity) {
	theTeacher = teacher;
	theCourse = course;
	theSectionNum = sectionNum;
	theCapacity = capacity;
	theStudents = new Person*[capacity+1](); //initialize all elements in array to nullptr
	//array size = max+1, no need to check i < capacity
	//only check for nullptr is fine because the last one is always nullptr
	//similar to string null terminated
}

/**
 * Section destructor.
 */
Section::~Section() {
	theTeacher = nullptr;
	theCourse = nullptr;
	theSectionNum = 0;
	theCapacity = 0;
	//A Section aggregates Persons associated with Course, so its destructor should not delete them
	//so only delete pointer
	delete []theStudents;
	theStudents = nullptr;
}

/**
 * Returns the section number.
 *
 * @return the section number for this section.
 */
unsigned int Section::sectionNumber() const {
	return theSectionNum;
}

/**
 * Returns the course for this section.
 *
 * @return the course for this section.
 */
Course* Section::course() const {
	return theCourse;
}

/**
 * The teacher for this section.
 *
 * @return the teacher for this section
 */
Person* Section::teacher() const {
	return theTeacher;
}

/**
 * Add a student to this section.
 *
 * @param student the student
 * @return true if the student was added, or false
 * if person is the teacher, the person was already
 * in the section, or the section is at capacity
 */
bool Section::addStudent(Person* student) {
	//thestudent can't be the teacher
	if (student == theTeacher) {
		return false;
	}
	for (int i = 0; i < theCapacity; i++) {
		//the person was already in the section
		if (theStudents[i] != nullptr) {
			if (student == theStudents[i]) {
				return false;
			}
		}
		//find nllptr, add student if there is avaliable position
		else {
			theStudents[i] = student;
			return true;
		}
	}
	//the section is at cpacity
	return false;
}

/**
 * Fill in the array of students for this section, up to maxStudents.
 *
 * @param students the array of students
 * @param maxStudents the maximum number of students to return
 * @return the actual number of students returned
 */
unsigned int Section::students(Person *students[], int nStudents) const {
	unsigned int number = 0;
	for (int i = 0; theStudents[i] != nullptr && number < nStudents; i++) {
		if (students != nullptr) {
			students[i] = theStudents[i];
		}
		number++;
	}
	return number;
}

/**
 * The number of students enrolled in this section.
 *
 * @return the number of students enrolled in this section
 */
unsigned int Section::enrollment() const {
	return students(nullptr, theCapacity);
}

/**
 * Returns the section capacity.
 *
 * @return the section capacity
 */
unsigned int Section::capacity() const {
	return theCapacity;
}
} /* namespace CS_5004 */

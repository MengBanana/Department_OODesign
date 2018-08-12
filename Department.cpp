/*
 * Department.cpp
 *
 *  Created on: May 22, 2018
 *      Author: Xinmeng Zhang
 */

#include "Department.h"
#include "Person.h"
#include "Course.h"

namespace CS_5004 {

/**
 * Create a new department.
 *
 * @param name department name
 * @param maxCourses the maximum number of courses
 * @param maxMembers the maximum number of members
 */
Department::Department(const string &name, unsigned int maxCourses, unsigned int maxMembers) {
	deptName = name;
	this->maxCourses = maxCourses; //argument has same name with field, use this
	this->maxMembers = maxMembers;
	theCourses = new Course*[maxCourses+1](); //initialize all elements in array to nullptr
	theMembers = new Person*[maxMembers+1]();
	//array size = max+1, no need to check i < capacity
	//only check for nullptr is fine because the last one is always nullptr
	//similar to string null terminated
}

/**
 * Department destructor.
 * Delete Course and Person at the same time of implement department destructor
 */
Department::~Department() {
	//delete theMembers
	for (int i = 0; theMembers[i] != nullptr; i++) {
		// theMemebers length = max + 1, so no need to check i < maxMembers
		delete theMembers[i];
		theMembers[i] = nullptr;
	}
	delete []theMembers;
	theMembers = nullptr;
	//reset maxMembers
	maxMembers = 0;
	//delete theCourses
	for (int i = 0; theCourses[i] != nullptr; i++) {
		delete theCourses[i];
		theCourses[i] = nullptr;
	}
	delete []theCourses;
	theCourses = nullptr;
	//reset maxCourses
	maxCourses  = 0;
	//need to clear deptName since it's field in department
	deptName.clear();
}

/**
 * Returns the name of the department.
 *
 * @return the name of the department
 */
const string& Department::name() const {
	return deptName;
}

/**
 * Add new student or teacher to the department
 * @param givenName the person's first
 * @param familyName the person's family name
 * @return the new student or teacher, or nullptr if could not add
 */
Person* Department::addMember(const string& familyName, const string& givenName) {
	for (int i = 0; i < maxMembers; i++) {
		//use i<maxMembers instead of theMembers[i]!=nullptr here
		//because theMembers length = maxMembers+1, the last position should always keep as nullptr
		//and also need to check each theMembers[i]!=nullptr
		//to make sure unique familyName and givenName of the person
		if (theMembers[i] != nullptr) {
			if (theMembers[i]->familyName() == familyName && theMembers[i]->givenName() == givenName) {
					return nullptr; //fail to add so can't return a pointer to Person
			}
		}
		//if nullptr means it's the first avaliable position we can add new Person
		else {
			Person* person = new Person(familyName, givenName, this);
			theMembers[i] = person;
			return person;
		}
	}
	//reach maxMemebers, can't add more
	return nullptr;
}

/**
 * Finds the person by their family and given names
 *
 * @param familyName the family name
 * @param givenName the given name
 * @return the person or nullptr of person not found
 */
Person* Department::findMember(const string& familyName, const string& givenName) const {
	for (int i = 0; theMembers[i] != nullptr; i++) {
		//when looking for sth in the array, could always use theMembers[i]!=nullptr
		//because the last position is always nullptr
		//both familyName and givenName match then we can return the pointer of that Person
		if (theMembers[i]->familyName() == familyName && theMembers[i]->givenName() == givenName) {
			return theMembers[i];
		}
	}
	//not found;
	return nullptr;
}


/**
 * Fill in the array of members of this department, up to maxMembers.
 *
 * @param members the array of members or nullptr for count only
 * @param nMembers the maximum number of members to return
 * @return the actual number of members returned
 */
unsigned int Department::members(Person* members[], int nMembers) const {
	unsigned int number = 0;
	//since nMembers maybe less than the actual members in the array, need to check number<nMembers
	for (int i = 0; theMembers[i] != nullptr && number < nMembers; i++) {
		//copy and fill in the array if not nullptr
		if (members != nullptr) {
			members[i] = theMembers[i];
		}
		//otherwise just keep track of the number of members
		number++;
	}
	//always return min(number of members, nMembers)
	return number;
}

/**
 * Returns number of members currently in the department.
 *
 * @return number of members currently in the department
 */
unsigned int Department::numMembers() const {
	//use nullptr for first parameter so we only need the count dont need to fill in the array
	return members(nullptr, maxMembers);
}

/**
 * Add a course for the department.
 *
 * @param courseName the name of the course
 * @param maxSections the maximum number of sections available
 * @return the new course or nullptr if the course could not be added
 */
Course* Department::addCourse(const string& courseName, unsigned int nSections) {
	for (int i = 0; i < maxCourses; i++) {
		//course must be unique in the department
		if (theCourses[i] != nullptr) {
			if (theCourses[i]->name() == courseName) {
				return nullptr;
			}
		}
		//if nullptr means it's the first avaliable position we can add new Course
		//will never reach the terminating nullptr because use i<maxCourses as stopping condition
		else {
			Course* course = new Course(courseName, nSections, this);
			theCourses[i] = course;
			return course;
		}
	}
	//reach maxCourse, can't add more
	return nullptr;
}

/**
 * Finds the course by its course name.
 *
 * @param courseName the course name
 * @return the course or nullptr if course not found
 */
Course* Department::findCourse(const string& courseName) const {
	for (int i = 0; theCourses[i] != nullptr; i++) {
		//find the course
		if (theCourses[i]->name() == courseName) {
			return theCourses[i];
		}
	}
	//not found;
	return nullptr;
}

/**
 * Fill in the array of courses of this department, up to maxCourses.
 *
 * @param courses the array of courses or nullptr for count only
 * @param nCourses the maximum number of courses to return
 * @return the actual number of courses returned
 */
unsigned int Department::courses(Course* courses[], int nCourses) const {
	unsigned int number = 0;
	for (int i = 0; theCourses[i] != nullptr && number < nCourses; i++) {
		//fill in the array if not nullptr
		if (courses != nullptr) {
			courses[i] = theCourses[i];
		}
		number++;
	}
	return number;
}

/**
 * Returns number of courses currently offered by the department.
 *
 * @return number of courses currently offered by the department
 */
unsigned int Department::numCourses() const {
	return courses(nullptr, maxCourses);
}


} /* namespace CS_5004 */

/*
 * Person.cpp
 *
 *  Created on: May 22, 2018
 *      Author: Xinmeng Zhang
 */

#include "Person.h"
#include "Department.h"
#include "Course.h"
#include "Section.h"

namespace CS_5004 {

/**
 * Creates a new student or teacher.
 *
 * @param familyName the family name
 * @param givenName the given name
 * @param dept the department
 */
Person::Person(const string& familyName, const string& givenName, Department* dept) {
	theFamilyName = familyName;
	theGivenName = givenName;
	theDept = dept;
}

/**
 * Person destructor
 */
Person::~Person() {
	theFamilyName.clear();
	theGivenName.clear();
	theDept = nullptr;
}

/**
 * Return the student or teacher given name.
 *
 * @return the student or teacher given name.
 */
const string& Person::givenName() const {
	return theGivenName;
}

/**
 * Return the student or teacher family name.
 *
 * @return the student or teacher family name
 */
const string& Person::familyName() const {
	return theFamilyName;
}

/**
 * Return the department of this student or teacher.
 *
 * @return the student or teacher department
 */
Department* Person::department() const {
	return theDept;
}

/**
 * Add this student to a section of a course.
 *
 * @param course the course
 * @param sectionNum the section number
 * @return true if the course was added
 */
bool Person::addCourse(Course* course, unsigned int sectionNum) {
	//find the sectioin then add
	//return true if the student was added, or false if person is the teacher, the person was already
	//in the section, or the section is at capacity
	return (course->findSection(sectionNum))->addStudent(this);
}

} /* namespace CS_5004 */












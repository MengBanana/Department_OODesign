/*
 * Course.cpp
 *
 *  Created on: May 22, 2018
 *      Author: Xinmeng Zhang
 */

#include "Course.h"
#include "Department.h"
#include "Person.h"
#include "Section.h"

namespace CS_5004 {

/**
 * Create a new course.
 * @param courseName the course name
 * @param maxSections max number of sections
 * @param dept the department
 */
Course::Course(const string &courseName, unsigned int maxSections, Department *dept) {
	this->courseName = courseName;
	this->maxSections = maxSections;
	theSections = new Section*[maxSections+1]();//initialize all elements in array to nullptr
	//array size = max+1, no need to check i < capacity
	//only check for nullptr is fine because the last one is always nullptr
	//similar to string null terminated
	theDept = dept;
}

/**
 * Course destructor
 * Delete sections when implement course destructor
 * Does not delete department it reference to
 */
Course::~Course() {
	//delete all sections when implete Couse destructor
	for (int i = 0; theSections[i] != nullptr; i++) {
		delete theSections[i];
		theSections[i] = nullptr;
	}
	delete []theSections;
	theSections = nullptr;
	//delete courseName string
	courseName.clear();
	//reset maxSections
	maxSections = 0;
	//delete connection with Department but not delete the department
	theDept = nullptr;
}

/**
 * Returns course name
 *
 * @return name of course
 */
const string& Course::name() const {
	return courseName;
}

/**
 * Gets department for this course.
 *
 * @return the department
 */
Department* Course::department() const{
	return theDept;
}

/**
 * Add a section for this course.
 *
 * @param teacher the teacher
 * @param capacity the course capacity
 * @return the new section or nullptr if the section can't be added
 */
Section* Course::addSection(Person* teacher, unsigned int capacity){
	for (int i = 0; i < maxSections; i++) {
		//add new section to the first avaliable position
		if (theSections[i] == nullptr) {
			//based on the unit test, sectionNum starts from 1 so use i+1 as sectionNum
			Section* section = new Section(teacher, this, i+1, capacity);
			theSections[i] = section;
			return section;
		}
	}
	//can't add more sections
	return nullptr;
}

/**
 * Find section by number.
 *
 * @param sectionNum the section number
 * @return the section or nullptr if not found
 */
Section* Course::findSection(unsigned int sectionNum) const {
	for (int i = 0; theSections[i] != nullptr; i++) {
		if (theSections[i]->sectionNumber() == sectionNum) {
			return theSections[i];
		}
	}
	//not found
	return nullptr;
}

/**
 * Fill in the array of sections for this course, up to nSections.
 *
 * @param sections the array of sections
 * @param nSections the maximum number of sections to return
 * @return the actual number of sections returned
 */
unsigned int Course::sections(Section *sections[], int nSections) const {
	unsigned int number = 0;
	for (int i = 0; theSections[i] != nullptr && number < nSections; i++) {
		//fill in the array if not nullptr
		if (sections != nullptr) {
			sections[i] = theSections[i];
		}
		number++;
	}
	return number;
}

/**
 * Returns number of sections currently offered.
 *
 * @return number of sections currently offered
 */
unsigned int Course::numSections() const {
	//set first argument for nullptr will only count the numbers
	return sections(nullptr, maxSections);
}

/**
 * Returns course enrollment
 *
 * @return enrollment for all sections
 */
unsigned int Course::enrollment() const {
	unsigned int number = 0;
	//iterate through all existing sections, and add all students together
	for (int i = 0; theSections[i] != nullptr; i++) {
		number += theSections[i]->enrollment();
	}
	return number;
}

} /* namespace CS_5004 */

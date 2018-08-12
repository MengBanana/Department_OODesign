/*
 * Course.h
 *
 *  @since May 20, 2018
 *  @author philip gust
 */

#ifndef COURSE_H_
#define COURSE_H_
#include <string>

using std::string;

namespace CS_5004 {
// forward declarations
class Department;
class Section;
class Person;

/**
 * This class represents a course in a department,
 * with a maximum number of sections available.
 */
class Course {
private:
	/** name of the course */
	string courseName;

	/** array of sections */
	Section **theSections;

	/** maximum number of sections of course */
	unsigned int maxSections;

	/** department of this course*/
	Department *theDept;

public:
	/**
	 * Create a new course.
	 * @param courseName the course name
	 * @param maxSections max number of sections
	 * @param dept the department
	 */
	Course(const string &courseName, unsigned int maxSections, Department *dept);

	/**
	 * Course destructor
	 */
	~Course();

	/**
	 * Returns course name
	 *
	 * @return name of course
	 */
	const string &name() const;

	/**
	 * Gets department for this course.
	 *
	 * @return the department
	 */
	Department *department() const;

	/**
	 * Add a section for this course.
	 *
	 * @param teacher the teacher
	 * @param capacity the course capacity
	 * @return the new section
	 */
	Section *addSection(Person *teacher, unsigned int capacity);

	/**
	 * Find section by number.
	 *
	 * @param sectionNum the section number
	 * @return the section or
	 */
	Section *findSection(unsigned int sectionNum) const;

	/**
	 * Fill in the array of sections for this course, up to nSections.
	 *
	 * @param sections the array of sections
	 * @param nSections the maximum number of sections to return
	 * @return the actual number of sections returned
	 */
	unsigned int sections(Section *sections[], int nSections) const;

	/**
	 * Returns number of sections currently offered.
	 *
	 * @return number of sections currently offered
	 */
	unsigned int numSections() const;

	/**
	 * Returns course enrollment
	 *
	 * @return enrollment for all sections
	 */
	unsigned int enrollment() const;

};

}  // namespace CS_5004

#endif /* COURSE_H_ */

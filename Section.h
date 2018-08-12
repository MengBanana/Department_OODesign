/*
 * Section.h
 *
 */

#ifndef SECTION_H_
#define SECTION_H_
#include <string>

using std::string;

namespace CS_5004 {
class Course;
class Person;

/**
 * This class represents a section of a course.
 */
class Section {
private:
	/** the teacher for the section */
	Person *theTeacher;

	/** an array of students */
	Person **theStudents;

	/** the course capacity */
	unsigned int theCapacity;

	/** the course */
	Course *theCourse;

	/** the section number */
	unsigned int theSectionNum;

public:
	/**
	 * Create a section of a course with a given capacity.
	 *
	 * @param teacher the teacher for the section
	 * @param course the course
	 * @param sectionNo the section number
	 * @param capacity  the section capacity
	 */
	Section(Person *teacher, Course *course, unsigned int sectionNum, unsigned int capacity);

	/**
	 * Section destructor.
	 */
	~Section();

	/**
	 * Returns the section number.
	 *
	 * @return the section number for this section.
	 */
	unsigned int sectionNumber() const;

	/**
	 * Returns the course for this section.
	 *
	 * @return the course for this section.
	 */
	Course *course() const ;

	/**
	 * The teacher for this section.
	 *
	 * @return the teacher for this section
	 */
	Person *teacher() const;

	/**
	 * Add a student to this section.
	 *
	 * @param student the student
	 * @return true if the student was added, or false
	 * if person is the teacher, the person was already
	 * in the section, or the section is at capacity
	 */
	bool addStudent(Person *student);

	/**
	 * Fill in the array of students for this section, up to maxStudents.
	 *
	 * @param students the array of students
	 * @param maxStudents the maximum number of students to return
	 * @return the actual number of students returned
	 */
	unsigned int students(Person *students[], int maxStudents) const;

	/**
	 * The number of students enrolled in this section.
	 *
	 * @return the number of students enrolled in this section
	 */
	unsigned int enrollment() const;

	/**
	 * Returns the section capacity.
	 *
	 * @return the section capacity
	 */
	unsigned int capacity() const;

};

} // namespace CS_5004

#endif /* SECTION_H_ */

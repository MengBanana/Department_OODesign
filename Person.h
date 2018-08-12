/*
 * Student.h
 *
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <string>

using std::string;

namespace CS_5004 {

// forward declarations
class Department;
class Course;

/**
 * This class represents a student or teacher in a department.
 */
class Person {
private:
	/** the given name */
	string theGivenName;

	/** the family name */
	string theFamilyName;

	/** the department */
	Department *theDept;

public:
	/**
	 * Creates a new student or teacher.
	 *
	 * @param familyName the family name
	 * @param givenName the given name
	 * @param dept the department
	 */
	Person(const string &familyName, const string &givenName, Department *dept);

	/**
	 * Person destructor
	 */
	~Person();

	/**
	 * Return the student or teacher given name.
	 *
	 * @return the student or teacher given name.
	 */
	const string &givenName() const;

	/**
	 * Return the student or teacher family name.
	 *
	 * @return the student or teacher family name
	 */
	const string &familyName() const;

	/**
	 * Return the department of this student or teacher.
	 *
	 * @return the student or teacher department
	 */
	Department *department() const;

	/**
	 * Add this student to a section of a course.
	 *
	 * @param course the course
	 * @param sectionNum the section number
	 * @return true if the course was added
	 */
	bool addCourse(Course* course, unsigned int sectionNum);

};

} // namespace CS_5004

#endif /* PERSON_H_ */

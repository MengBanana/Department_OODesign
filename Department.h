/*
 * Department.h
 *
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_
#include <string>

using std::string;

namespace CS_5004 {
// forward declarations
class Course;
class Person;

/**
 * This class represents a Department with members
 * (students and teachers), and courses.
 */
class Department {
private:
	/** the department name */
	string deptName;

	/** courses offered by the department */
	Course **theCourses;

	/** members of the department */
	Person **theMembers;

	/** maximum number of courses offered */
	int maxCourses;

	/** maximum number of members */
	int maxMembers;

public:
	/**
	 * Create a new department.
	 *
	 * @param name department name
	 * @param maxCourses the maximum number of courses
	 * @param maxMembers the maximum number of members
	 */
	Department(const string &name, unsigned int maxCourses,
			unsigned int maxMembers);

	/**
	 * Department destructor.
	 */
	~Department();

	/**
	 * Returns the name of the department.
	 *
	 * @return the name of the department
	 */
	const string& name() const;

	/**
	 * Add new student or teacher to the department
	 * @param givenName the person's first
	 * @param familyName the person's family name
	 * @return the new student or teacher, or nullptr if could not add
	 */
	Person *addMember(const string &familyName, const string &givenName);

	/**
	 * Finds the person by their family and given names
	 *
	 * @param familyName the family name
	 * @param givenName the given name
	 * @return the person or nullptr of person not found
	 */
	Person *findMember(const string &familyName, const string &givenName) const;

	/**
	 * Fill in the array of members of this department, up to maxMembers.
	 *
	 * @param members the array of members or nullptr for count only
	 * @param nMembers the maximum number of members to return
	 * @return the actual number of members returned
	 */
	unsigned int members(Person *members[], int nMembers) const;

	/**
	 * Returns number of members currently in the department.
	 *
	 * @return number of members currently in the department
	 */
	unsigned int numMembers() const;

	/**
	 * Add a course for the department.
	 *
	 * @param courseName the name of the course
	 * @param maxSections the maximum number of sections available
	 * @return the new course or nullptr if the course could not be added
	 */
	Course *addCourse(const string &courseName, unsigned int nSections);

	/**
	 * Finds the course by its course name.
	 *
	 * @param courseName the course name
	 * @return the course or nullptr if course not found
	 */
	Course *findCourse(const string &courseName) const;

	/**
	 * Fill in the array of courses of this department, up to maxCourses.
	 *
	 * @param courses the array of courses or nullptr for count only
	 * @param nCourses the maximum number of courses to return
	 * @return the actual number of courses returned
	 */
	unsigned int courses(Course *courses[], int nCourses) const;

	/**
	 * Returns number of courses currently offered by the department.
	 *
	 * @return number of courses currently offered by the department
	 */
	unsigned int numCourses() const;

};

} // namespace CS_5004

#endif /* DEPARTMENT_H_ */

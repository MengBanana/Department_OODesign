
/*
 * test,cpp
 *
 */

#include <cstdlib>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "Department.h"
#include "Course.h"
#include "Section.h"
#include "Person.h"

using namespace CS_5004;

void test() {
	unsigned long maxCourses = 2;
	unsigned long maxMembers = 20;
	unsigned long maxSections = 2;
	unsigned long maxStudents = 3;

	Department *dept = new Department("CCIS", maxCourses, maxMembers);
	CU_ASSERT_EQUAL(0, dept->numMembers());
	CU_ASSERT_EQUAL(0, dept->numCourses());
	CU_ASSERT_STRING_EQUAL("CCIS", dept->name().c_str());

	// string buffer to create names
	char sbuf[100];

	// add members (teachers and students) to the department
	for (int i = 0; i < maxMembers; i++) {
		sprintf(sbuf, "FamilyName-%02d", i);
		string familyName = string(sbuf);
		sprintf(sbuf, "GivenName-%02d", i);
		string givenName = string(sbuf);
		Person *member = dept->addMember(familyName, givenName);
		CU_ASSERT_PTR_NOT_NULL(member);
		CU_ASSERT_STRING_EQUAL(member->givenName().c_str(), givenName.c_str())
		CU_ASSERT_STRING_EQUAL(member->familyName().c_str(), familyName.c_str())
		CU_ASSERT_EQUAL(i+1, dept->numMembers());
	}

	// add courses and sections to the department
	for (int i = 0; i < maxCourses; i++) {
		sprintf(sbuf, "Course-%02d", i);
		string courseName = string(sbuf);
		Course *course = dept->addCourse(courseName, maxSections);
		CU_ASSERT_PTR_NOT_NULL(course);
		unsigned int nc = dept->numCourses();
		CU_ASSERT_EQUAL(i+1, nc);
		CU_ASSERT_STRING_EQUAL(course->name().c_str(), courseName.c_str());
		CU_ASSERT_EQUAL(0, course->numSections());

		// add first section
		Person *teacher = dept->findMember("FamilyName-00", "GivenName-00");
		CU_ASSERT_PTR_NOT_NULL(teacher);
		Section *section = course->addSection(teacher, maxStudents);
		CU_ASSERT_PTR_NOT_NULL(section);
		unsigned int enrollment = section->enrollment();
		CU_ASSERT_EQUAL(0, enrollment);
		unsigned int sectNum = section->sectionNumber();
		CU_ASSERT_EQUAL(1, sectNum);

		// add students to first section
		Person *student = dept->findMember("FamilyName-10", "GivenName-10");
		CU_ASSERT_PTR_NOT_NULL(student);
		bool b = section->addStudent(student);
		CU_ASSERT_TRUE(b);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(1, enrollment);

		student = dept->findMember("FamilyName-11", "GivenName-11");
		CU_ASSERT_PTR_NOT_NULL(student);
		b = section->addStudent(student);
		CU_ASSERT_TRUE(b);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(2, enrollment);

		student = dept->findMember("FamilyName-12", "GivenName-12");
		CU_ASSERT_PTR_NOT_NULL(student);
		b = section->addStudent(student);
		CU_ASSERT_TRUE(b);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(3, enrollment);

		// list students in first section
		Person *students1[section->enrollment()];
		unsigned int np = section->students(students1, section->enrollment());
		for (int i = 0; i < np; i++) {
			CU_ASSERT_PTR_NOT_NULL(students1[i]);
			CU_ASSERT_EQUAL(students1[i]->department(), dept);
		}

		// add second section
		teacher = dept->findMember("FamilyName-01", "GivenName-01");
		CU_ASSERT_PTR_NOT_NULL(teacher);
		section = course->addSection(teacher, maxStudents);
		CU_ASSERT_PTR_NOT_NULL(section);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(0, enrollment);
		sectNum = section->sectionNumber();
		CU_ASSERT_EQUAL(2, sectNum);

		// add students to second section
		student = dept->findMember("FamilyName-13", "GivenName-13");
		CU_ASSERT_PTR_NOT_NULL(student);
		section->addStudent(student);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(1, enrollment);

		student = dept->findMember("FamilyName-14", "GivenName-14");
		CU_ASSERT_PTR_NOT_NULL(student);
		section->addStudent(student);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(2, enrollment);

		student = dept->findMember("FamilyName-15", "GivenName-15");
		CU_ASSERT_PTR_NOT_NULL(student);
		section->addStudent(student);
		enrollment = section->enrollment();
		CU_ASSERT_EQUAL(3, enrollment);

		// list students in second section
		Person *students2[section->enrollment()];
		np = section->students(students2, section->enrollment());
		for (int i = 0; i < np; i++) {
			CU_ASSERT_PTR_NOT_NULL(students2[i]);
			CU_ASSERT_EQUAL(students2[i]->department(), dept);
		}

		np = course->enrollment();
		CU_ASSERT_EQUAL(6, np);
	}

	delete dept;
}

/**
 * Test all the functions for this application.
 *
 * @return test error code
 */
static CU_ErrorCode test_all() {
	// initialize the CUnit test registry -- only once per application
	CU_initialize_registry();

	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("function_tests", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test", test);

	// run all test suites using the basic interface
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	// display information on failures that occurred
	CU_basic_show_failures(CU_get_failure_list());

	// Clean up registry and return status
	CU_cleanup_registry();
	return CU_get_error();
}

/**
 * Main program to invoke test functions
 *
 * @return the exit status of the program
 */
int main(void) {
	// test all the functions
	CU_ErrorCode code = test_all();

	return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}

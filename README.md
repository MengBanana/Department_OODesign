# Department_OODesign

Encapsulation and commosition by implementing a data model for University academic department that has courses with multiple sections, 
and people who are teachers or students. A Department is an aggregation of Person and Course. The aggregation enables a Person who 
is a student or teacher in a department to be found based on family and given name, and a Course of the Department to be found based 
on a course name. The family/given name combination must tbe unique among Person instances, and the course name must be unique 
among Courses for the Department.

A Course contains multiple Sections. Each Section is an association between a Person who is either a student or teacher and the Course. 
Each Section of a Course has one teacher. A teacher can teach multiple Sections of multiple Courses. A student can take Sections of 
multiple Courses. A Person cannot be the teacher of a Course for which the Person is also a student.

Notes: class Department uses fixed arrays of Person and Course pointers to aggregate its Person and Course objects. The size of the 
arrays is provided with the constructor and saved with the Department. The arrays are allocated by the constructor. Similarly, 
Section uses a fixed array of Person pointers to associate the students in the Section with the course.

Rather than storing the current number of elemements in the arrays, the array slots are initialized to nullptr. The algorithm that 
inserts an element searches the array for a nullptr slot where the new entry will be added, or reaches the end of the array if the 
array is full In C++, elements of an array of pointers are initialized to nullptr using a declaration like new Person*maxMembers 
with parens after the square brackets.

Individual Course, Section,and Person objects are added but not deleted. Fully implment the destructors for 
all classes because a Department can be deleted, which in turn causes all of the other objects to be deleted. Course creates and 
deletes its Section elements, but does not delete the Department that it references. A Section aggregates Persons associated with Course, 
so its destructor should not delete them. Department creates the Person and Department objects it adds, so it should delete them in its 
destructor.

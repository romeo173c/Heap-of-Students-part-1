loadStudents()
- Read line from studentString 
- make new studnet object on heap
- init studentString on Student object
- include Student pointer to vector
- end 

printStudent()
- print a list of students 
- for every student in students 
- call printStudnet
- end 

showStudentNames()
- display showStudentNames
- for every student in students
- print getLastFirst()
- end 

findStudent()
- Print "Enter student last name:"
- for every student in students 
- if lastname -> contains searchName
	call printStudent 
	set found = True 
	end
- if found == false
	print "Student can not be found."
	end 


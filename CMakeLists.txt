cmake_minimum_required(VERSION 3.0)

set(PROJECT_SOURCES
        wptr_managed.h
        wptr.h
        main.cpp
        wptr_managed_tests.h
        wptr_managed_tests.cpp
        wptr_tests.h
        wptr_tests.cpp
        awptr.h
        awptr_managed.h
        wmptr_tests.h
        wmptr_tests.cpp
)

#wptr_managed tests

#common for all tests
set(wptr_managed_tests
        wptr_managed_tests.h
        wptr_managed_tests.cpp
)

#separate tests

set(wptr_managed_test_constructor
        ${wptr_managed_tests}
        wptr_managed_test_constructor.cpp
)

set(wptr_managed_test_constructor_copy
        ${wptr_managed_tests}
        wptr_managed_test_constructor_copy.cpp
)

set(wptr_managed_test_reference
        ${wptr_managed_tests}
        wptr_managed_test_reference.cpp
)

set(wptr_managed_test_member_access
        ${wptr_managed_tests}
        wptr_managed_test_member_access.cpp
)


#wptr tests

#common for all tests
set(wptr_tests
        wptr_tests.h
        wptr_tests.cpp
)

#separate tests

set(wptr_test_constructor
        ${wptr_tests}
        wptr_test_constructor.cpp
)

set(wptr_test_constructor_copy
        ${wptr_tests}
        wptr_test_constructor_copy.cpp
)

set(wptr_test_assignment
        ${wptr_tests}
        wptr_test_assignment.cpp
)

set(wptr_test_reference
        ${wptr_tests}
        wptr_test_reference.cpp
)

set(wptr_test_member_access
        ${wptr_tests}
        wptr_test_member_access.cpp
)


#wmptr tests

#common for all tests
set(wmptr_tests
        wmptr_tests.h
        wmptr_tests.cpp
)

#separete tests

set (wmptr_test_assignment
        ${wmptr_tests}
        wmptr_test_assignment.cpp
)

set (wmptr_test_constructor
        ${wmptr_tests}
        wmptr_test_constructor
)

set (wmptr_test_constructor_copy
        ${wmptr_tests}
        wmptr_test_constructor_copy.cpp
)

set (wmptr_test_member_access
        ${wmptr_tests}
        wmptr_test_member_access.cpp
)

set (wmptr_test_reference
        ${wmptr_tests}
        wmptr_test_reference.cpp
)

set (wmptr_test_setObject
        ${wmptr_tests}
        wmptr_test_setObject.cpp
)

set (wmptr_test_setOffset
        ${wmptr_tests}
        wmptr_test_setOffset.cpp
)


project(wise_pointers)

include(CTest)

add_executable(wise_pointers ${PROJECT_SOURCES})

#test executables

#wptr_managed tests

add_executable(wptr_managed_test_constructor ${wptr_managed_test_constructor})
add_executable(wptr_managed_test_constructor_copy ${wptr_managed_test_constructor_copy})
add_executable(wptr_managed_test_reference ${wptr_managed_test_reference})
add_executable(wptr_managed_test_member_access ${wptr_managed_test_member_access})

#wptr tests

add_executable(wptr_test_constructor ${wptr_test_constructor})
add_executable(wptr_test_constructor_copy ${wptr_test_constructor_copy})
add_executable(wptr_test_assignment ${wptr_test_assignment})
add_executable(wptr_test_reference ${wptr_test_reference})
add_executable(wptr_test_member_access ${wptr_test_member_access})

#wmptr tests

add_executable(wmptr_test_assignment ${wmptr_test_assignment})
add_executable(wmptr_test_constructor ${wmptr_test_constructor})
add_executable(wmptr_test_constructor_copy ${wmptr_test_constructor_copy})
add_executable(wmptr_test_member_access ${wmptr_test_member_access})
add_executable(wmptr_test_reference ${wmptr_test_reference})
add_executable(wmptr_test_setObject ${wmptr_test_setObject})
add_executable(wmptr_test_setOffset ${wmptr_test_setOffset})


#tests

#wptr_managed tests

add_test(NAME wptr_managed_constructor COMMAND wptr_managed_test_constructor)
add_test(NAME wptr_managed_copy_constructor COMMAND wptr_managed_test_constructor_copy)
add_test(NAME wptr_managed_reference COMMAND wptr_managed_test_reference)
add_test(NAME wptr_managed_member_access COMMAND wptr_managed_test_member_access)

#wptr tests

add_test(NAME wptr_constructor COMMAND wptr_test_constructor)
add_test(NAME wptr_constructor_copy COMMAND wptr_test_constructor_copy)
add_test(NAME wptr_assignment COMMAND wptr_test_assignment)
add_test(NAME wptr_reference COMMAND wptr_test_reference)
add_test(NAME wptr_member_access COMMAND wptr_test_member_access)

#wmptr tests

add_test(NAME wmptr_test_assignment COMMAND wmptr_test_assignment)
add_test(NAME wmptr_test_constructor COMMAND wmptr_test_constructor)
add_test(NAME wmptr_test_constructor_copy COMMAND wmptr_test_constructor_copy)
add_test(NAME wmptr_test_member_access COMMAND wmptr_test_member_access)
add_test(NAME wmptr_test_reference COMMAND wmptr_test_reference)
add_test(NAME wmptr_test_setObject COMMAND wmptr_test_setObject)
add_test(NAME wmptr_test_setOffset COMMAND wmptr_test_setOffset)

install(TARGETS wise_pointers RUNTIME DESTINATION bin)

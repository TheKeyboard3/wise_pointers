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
        wptr_simple.h
        wptr_readable.h
        wptr_writable.h
        wptr_agnostic.h
        wptr_simple_tests.h
        wptr_simple_tests.cpp
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


#wptr_simple tests

#common for all tests
set(wptr_simple_tests
        wptr_simple_tests.h
        wptr_simple_tests.cpp
        wptr_simple.h
        wptr_readable.h
        wptr_writable.h
        wptr_agnostic.h
)

#separate tests

set(wptr_simple_test_constructor
        ${wptr_simple_tests}
        wptr_simple_test_constructor.cpp
)

set(wptr_simple_test_constructor_copy
        ${wptr_simple_tests}
        wptr_simple_test_constructor_copy.cpp
)

set(wptr_simple_test_assignment
        ${wptr_simple_tests}
        wptr_simple_test_assignment.cpp
)

set(wptr_simple_test_reference
        ${wptr_simple_tests}
        wptr_simple_test_reference.cpp
)

set(wptr_simple_test_member_access
        ${wptr_simple_tests}
        wptr_simple_test_member_access.cpp
)

set(wptr_simple_test_comparison
        ${wptr_simple_tests}
        wptr_simple_test_comparison.cpp
)

set(wptr_simple_test_duplicate
        ${wptr_simple_tests}
        wptr_simple_test_duplicate.cpp
)


#wptr_inheritance tests

#common for all tests
set(wptr_inheritance_tests
        wptr_inheritance_tests.h
        wptr_inheritance_tests.cpp
        wptr_inheritance.h
        wptr_readable.h
        wptr_writable.h
        wptr_agnostic.h
)

#separate tests

set(wptr_inheritance_test_constructor
        ${wptr_inheritance_tests}
        wptr_inheritance_test_constructor.cpp
)

set(wptr_inheritance_test_constructor_copy
        ${wptr_inheritance_tests}
        wptr_inheritance_test_constructor_copy.cpp
)

set(wptr_inheritance_test_assignment
        ${wptr_inheritance_tests}
        wptr_inheritance_test_assignment.cpp
)

set(wptr_inheritance_test_reference
        ${wptr_inheritance_tests}
        wptr_inheritance_test_reference.cpp
)

set(wptr_inheritance_test_member_access
        ${wptr_inheritance_tests}
        wptr_inheritance_test_member_access.cpp
)

set(wptr_inheritance_test_comparison
        ${wptr_inheritance_tests}
        wptr_inheritance_test_comparison.cpp
)

set(wptr_inheritance_test_duplicate
        ${wptr_inheritance_tests}
        wptr_inheritance_test_duplicate.cpp
)


#wptr_itr tests

#common for all tests
set(wptr_itr_tests
        wptr_itr_tests.h
        wptr_itr_tests.cpp
        wptr_itr.h
        wptr_readable.h
        wptr_writable.h
        wptr_agnostic.h
)

#separate tests

set(wptr_itr_test_constructor
        ${wptr_itr_tests}
        wptr_itr_test_constructor.cpp
)

set(wptr_itr_test_constructor_copy
        ${wptr_itr_tests}
        wptr_itr_test_constructor_copy.cpp
)

set(wptr_itr_test_assignment
        ${wptr_itr_tests}
        wptr_itr_test_assignment.cpp
)

set(wptr_itr_test_reference
        ${wptr_itr_tests}
        wptr_itr_test_reference.cpp
)

set(wptr_itr_test_member_access
        ${wptr_itr_tests}
        wptr_itr_test_member_access.cpp
)

set(wptr_itr_test_comparison
        ${wptr_itr_tests}
        wptr_itr_test_comparison.cpp
)

set(wptr_itr_test_duplicate
        ${wptr_itr_tests}
        wptr_itr_test_duplicate.cpp
)


#wptr_dereference_accessor tests

#common for all tests
set(wptr_dereference_accessor_tests
        wptr_dereference_accessor_tests.h
        wptr_dereference_accessor_tests.cpp
        wptr_dereference_accessor.h
)

#separate tests

set(wptr_dereference_accessor_test_access
        ${wptr_dereference_accessor_tests}
        wptr_dereference_accessor_test_access.cpp
)

set(wptr_dereference_accessor_test_constructor
        ${wptr_dereference_accessor_tests}
        wptr_dereference_accessor_test_constructor.cpp
)

set(wptr_dereference_accessor_test_constructor_copy
        ${wptr_dereference_accessor_tests}
        wptr_dereference_accessor_test_constructor_copy.cpp
)

set(wptr_dereference_accessor_test_assignment
        ${wptr_dereference_accessor_tests}
        wptr_dereference_accessor_test_assignment.cpp
)

#wptr_no_accessor tests

#common for all tests
set(wptr_no_accessor_tests
        wptr_no_accessor_tests.h
        wptr_no_accessor_tests.cpp
        wptr_no_accessor.h
)

#separate tests

set(wptr_no_accessor_test_access
        ${wptr_no_accessor_tests}
        wptr_no_accessor_test_access.cpp
)

set(wptr_no_accessor_test_constructor
        ${wptr_no_accessor_tests}
        wptr_no_accessor_test_constructor.cpp
)

set(wptr_no_accessor_test_constructor_copy
        ${wptr_no_accessor_tests}
        wptr_no_accessor_test_constructor_copy.cpp
)

set(wptr_no_accessor_test_assignment
        ${wptr_no_accessor_tests}
        wptr_no_accessor_test_assignment.cpp
)


#wptr_inheritance_accessor tests

#common for all tests
set(wptr_inheritance_accessor_tests
        wptr_inheritance_accessor_tests.h
        wptr_inheritance_accessor_tests.cpp
        wptr_inheritance_accessor.h
)

#separate tests

set(wptr_inheritance_accessor_test_access
        ${wptr_inheritance_accessor_tests}
        wptr_inheritance_accessor_test_access.cpp
)

set(wptr_inheritance_accessor_test_constructor
        ${wptr_inheritance_accessor_tests}
        wptr_inheritance_accessor_test_constructor.cpp
)

set(wptr_inheritance_accessor_test_constructor_copy
        ${wptr_inheritance_accessor_tests}
        wptr_inheritance_accessor_test_constructor_copy.cpp
)

set(wptr_inheritance_accessor_test_assignment
        ${wptr_inheritance_accessor_tests}
        wptr_inheritance_accessor_test_assignment.cpp
)


#wptr_itr_accessor tests

#common for all tests
set(wptr_itr_accessor_tests
        wptr_itr_accessor_tests.h
        wptr_itr_accessor_tests.cpp
        wptr_itr_accessor.h
)

#separate tests

set(wptr_itr_accessor_test_constructor
        ${wptr_itr_accessor_tests}
        wptr_itr_accessor_test_constructor.cpp
)

set(wptr_itr_accessor_test_constructor_copy
        ${wptr_itr_accessor_tests}
        wptr_itr_accessor_test_constructor_copy.cpp
)

set(wptr_itr_accessor_test_assignment
        ${wptr_itr_accessor_tests}
        wptr_itr_accessor_test_assignment.cpp
)

set(wptr_itr_accessor_test_access
        ${wptr_itr_accessor_tests}
        wptr_itr_accessor_test_access.cpp
)

set(wptr_itr_accessor_test_comparison
        ${wptr_itr_accessor_tests}
        wptr_itr_accessor_test_comparison.cpp
)


#wptr_offset_accessor tests

#common for all tests
set(wptr_offset_accessor_tests
        wptr_offset_accessor_tests.h
        wptr_offset_accessor_tests.cpp
        wptr_offset_accessor.h
)

#separate tests

set(wptr_offset_accessor_test_constructor
        ${wptr_offset_accessor_tests}
        wptr_offset_accessor_test_constructor.cpp
)

set(wptr_offset_accessor_test_constructor_copy
        ${wptr_offset_accessor_tests}
        wptr_offset_accessor_test_constructor_copy.cpp
)

set(wptr_offset_accessor_test_assignment
        ${wptr_offset_accessor_tests}
        wptr_offset_accessor_test_assignment.cpp
)

set(wptr_offset_accessor_test_access
        ${wptr_offset_accessor_tests}
        wptr_offset_accessor_test_access.cpp
)

set(wptr_offset_accessor_test_comparison
        ${wptr_offset_accessor_tests}
        wptr_offset_accessor_test_comparison.cpp
)

#wptr_accessor_chain tests

#common for all tests
set(wptr_accessor_chain_tests
        wptr_accessor_chain_tests.h
        wptr_accessor_chain_tests.cpp
        wptr_accessor_chain.h
)

#separate tests

set(wptr_accessor_chain_test_constructor
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_constructor.cpp
)

set(wptr_accessor_chain_test_access
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_access.cpp
)
set(wptr_accessor_chain_test_assignment
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_assignment.cpp
)
set(wptr_accessor_chain_test_constructor
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_constructor.cpp
)
set(wptr_accessor_chain_test_constructor_base_readable
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_constructor_base_readable.cpp
)
set(wptr_accessor_chain_test_constructor_copy
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_constructor_copy.cpp
)
set(wptr_accessor_chain_test_constructor_readable
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_constructor_readable.cpp
)
set(wptr_accessor_chain_test_setAccessor
        ${wptr_accessor_chain_tests}
        wptr_accessor_chain_test_setAccessor.cpp
)


#wptr_accessor_wrap tests

#common for all tests
set(wptr_accessor_wrap_tests
        wptr_accessor_wrap_tests.h
        wptr_accessor_wrap_tests.cpp
        wptr_accessor_wrap.h
)

#separate tests
set(wptr_accessor_wrap_test_access
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_access.cpp
)
set(wptr_accessor_wrap_test_assignment
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_assignment.cpp
)
set(wptr_accessor_wrap_test_comparison
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_comparison.cpp
)
set(wptr_accessor_wrap_test_constructor
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_constructor.cpp
)
set(wptr_accessor_wrap_test_constructor_base_readable
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_constructor_base_readable.cpp
)
set(wptr_accessor_wrap_test_constructor_copy
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_constructor_copy.cpp
)
set(wptr_accessor_wrap_test_constructor_readable
        ${wptr_accessor_wrap_tests}
        wptr_accessor_wrap_test_constructor_readable.cpp
)



#wptr_wrapped tests

#common for all tests
set(wptr_wrapped_tests
        wptr_wrapped_tests.h
        wptr_wrapped_tests.cpp
        wptr_wrapped.h
)

#separate tests
set(wptr_wrapped_test_assignment
        ${wptr_wrapped_tests}
        wptr_wrapped_test_assignment.cpp
)

set(wptr_wrapped_test_constructor
        ${wptr_wrapped_tests}
        wptr_wrapped_test_constructor.cpp
)

set(wptr_wrapped_test_constructor_object
        ${wptr_wrapped_tests}
        wptr_wrapped_test_constructor_object.cpp
)

set(wptr_wrapped_test_constructor_base_readable
        ${wptr_wrapped_tests}
        wptr_wrapped_test_constructor_base_readable.cpp
)

set(wptr_wrapped_test_constructor_base_readable_readable
        ${wptr_wrapped_tests}
        wptr_wrapped_test_constructor_base_readable_readable.cpp
)

set(wptr_wrapped_test_constructor_copy
        ${wptr_wrapped_tests}
        wptr_wrapped_test_constructor_copy.cpp
)

set(wptr_wrapped_test_constructor_object_readable
        ${wptr_wrapped_tests}
        wptr_wrapped_test_constructor_object_readable.cpp
)

set(wptr_wrapped_test_member_access
        ${wptr_wrapped_tests}
        wptr_wrapped_test_member_access.cpp
)


#wptr_complex tests

#common for all tests
set(wptr_complex_tests
        wptr_complex_tests.h
        wptr_complex_tests.cpp
        wptr_complex.h
)

#separate tests
set(wptr_complex_test_assignment
        ${wptr_complex_tests}
        wptr_complex_test_assignment.cpp
)

set(wptr_complex_test_assignment
        ${wptr_complex_tests}
        wptr_complex_test_assignment.cpp
)

set(wptr_complex_test_assignment_base_readable
        ${wptr_complex_tests}
        wptr_complex_test_assignment_base_readable.cpp
)

set(wptr_complex_test_comparison
        ${wptr_complex_tests}
        wptr_complex_test_comparison.cpp
)

set(wptr_complex_test_constructor
        ${wptr_complex_tests}
        wptr_complex_test_constructor.cpp
)

set(wptr_complex_test_constructor_base_readable_accessor
        ${wptr_complex_tests}
        wptr_complex_test_constructor_base_readable_accessor.cpp
)

set(wptr_complex_test_constructor_base_readable_base_readable
        ${wptr_complex_tests}
        wptr_complex_test_constructor_base_readable_base_readable.cpp
)

set(wptr_complex_test_constructor_base_readable_readable
        ${wptr_complex_tests}
        wptr_complex_test_constructor_base_readable_readable.cpp
)

set(wptr_complex_test_constructor_copy
        ${wptr_complex_tests}
        wptr_complex_test_constructor_copy.cpp
)

set(wptr_complex_test_constructor_obj_accessor
        ${wptr_complex_tests}
        wptr_complex_test_constructor_obj_accessor.cpp
)

set(wptr_complex_test_constructor_obj_base_readable
        ${wptr_complex_tests}
        wptr_complex_test_constructor_obj_base_readable.cpp
)

set(wptr_complex_test_constructor_obj_readable
        ${wptr_complex_tests}
        wptr_complex_test_constructor_obj_readable.cpp
)

set(wptr_complex_test_duplicate
        ${wptr_complex_tests}
        wptr_complex_test_duplicate.cpp
)

set(wptr_complex_test_empty
        ${wptr_complex_tests}
        wptr_complex_test_empty.cpp
)

set(wptr_complex_test_getAccessor
        ${wptr_complex_tests}
        wptr_complex_test_getAccessor.cpp
)

set(wptr_complex_test_member_access
        ${wptr_complex_tests}
        wptr_complex_test_member_access.cpp
)

set(wptr_complex_test_reference
        ${wptr_complex_tests}
        wptr_complex_test_reference.cpp
)

set(wptr_complex_test_setAccessor_base_readable
        ${wptr_complex_tests}
        wptr_complex_test_setAccessor_base_readable.cpp
)

set(wptr_complex_test_setAccessor_readable
        ${wptr_complex_tests}
        wptr_complex_test_setAccessor_readable.cpp
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


#wptr_simple tests

add_executable(wptr_simple_test_constructor ${wptr_simple_test_constructor})
add_executable(wptr_simple_test_constructor_copy ${wptr_simple_test_constructor_copy})
add_executable(wptr_simple_test_assignment ${wptr_simple_test_assignment})
add_executable(wptr_simple_test_reference ${wptr_simple_test_reference})
add_executable(wptr_simple_test_member_access ${wptr_simple_test_member_access})
add_executable(wptr_simple_test_comparison ${wptr_simple_test_comparison})
add_executable(wptr_simple_test_duplicate ${wptr_simple_test_duplicate})


#wptr_inheritance tests

add_executable(wptr_inheritance_test_constructor ${wptr_inheritance_test_constructor})
add_executable(wptr_inheritance_test_constructor_copy ${wptr_inheritance_test_constructor_copy})
add_executable(wptr_inheritance_test_assignment ${wptr_inheritance_test_assignment})
add_executable(wptr_inheritance_test_reference ${wptr_inheritance_test_reference})
add_executable(wptr_inheritance_test_member_access ${wptr_inheritance_test_member_access})
add_executable(wptr_inheritance_test_comparison ${wptr_inheritance_test_comparison})
add_executable(wptr_inheritance_test_duplicate ${wptr_inheritance_test_duplicate})


#wptr_itr tests

add_executable(wptr_itr_test_constructor ${wptr_itr_test_constructor})
add_executable(wptr_itr_test_constructor_copy ${wptr_itr_test_constructor_copy})
add_executable(wptr_itr_test_assignment ${wptr_itr_test_assignment})
add_executable(wptr_itr_test_reference ${wptr_itr_test_reference})
add_executable(wptr_itr_test_member_access ${wptr_itr_test_member_access})
add_executable(wptr_itr_test_comparison ${wptr_itr_test_comparison})
add_executable(wptr_itr_test_duplicate ${wptr_itr_test_duplicate})


#wptr_dereference_accessor tests

add_executable(wptr_dereference_accessor_test_access ${wptr_dereference_accessor_test_access})
add_executable(wptr_dereference_accessor_test_constructor ${wptr_dereference_accessor_test_constructor})
add_executable(wptr_dereference_accessor_test_constructor_copy ${wptr_dereference_accessor_test_constructor_copy})
add_executable(wptr_dereference_accessor_test_assignment ${wptr_dereference_accessor_test_assignment})


#wptr_no_accessor tests

add_executable(wptr_no_accessor_test_access ${wptr_no_accessor_test_access})
add_executable(wptr_no_accessor_test_constructor ${wptr_no_accessor_test_constructor})
add_executable(wptr_no_accessor_test_constructor_copy ${wptr_no_accessor_test_constructor_copy})
add_executable(wptr_no_accessor_test_assignment ${wptr_no_accessor_test_assignment})


#wptr_iheritance_accessor tests

add_executable(wptr_inheritance_accessor_test_access ${wptr_inheritance_accessor_test_access})
add_executable(wptr_inheritance_accessor_test_constructor ${wptr_inheritance_accessor_test_constructor})
add_executable(wptr_inheritance_accessor_test_constructor_copy ${wptr_inheritance_accessor_test_constructor_copy})
add_executable(wptr_inheritance_accessor_test_assignment ${wptr_inheritance_accessor_test_assignment})


#wptr_itr_accessor tests

add_executable(wptr_itr_accessor_test_constructor ${wptr_itr_accessor_test_constructor})
add_executable(wptr_itr_accessor_test_constructor_copy ${wptr_itr_accessor_test_constructor_copy})
add_executable(wptr_itr_accessor_test_assignment ${wptr_itr_accessor_test_assignment})
add_executable(wptr_itr_accessor_test_access ${wptr_itr_accessor_test_access})
add_executable(wptr_itr_accessor_test_comparison ${wptr_itr_accessor_test_comparison})


#wptr_offset_accessor tests

add_executable(wptr_offset_accessor_test_constructor ${wptr_offset_accessor_test_constructor})
add_executable(wptr_offset_accessor_test_constructor_copy ${wptr_offset_accessor_test_constructor_copy})
add_executable(wptr_offset_accessor_test_assignment ${wptr_offset_accessor_test_assignment})
add_executable(wptr_offset_accessor_test_access ${wptr_offset_accessor_test_access})
add_executable(wptr_offset_accessor_test_comparison ${wptr_offset_accessor_test_comparison})


#wptr_accessor_chain tests

add_executable(wptr_accessor_chain_test_access ${wptr_accessor_chain_test_access})
add_executable(wptr_accessor_chain_test_assignment ${wptr_accessor_chain_test_assignment})
add_executable(wptr_accessor_chain_test_constructor ${wptr_accessor_chain_test_constructor})
add_executable(wptr_accessor_chain_test_constructor_base_readable ${wptr_accessor_chain_test_constructor_base_readable})
add_executable(wptr_accessor_chain_test_constructor_copy ${wptr_accessor_chain_test_constructor_copy})
add_executable(wptr_accessor_chain_test_constructor_readable ${wptr_accessor_chain_test_constructor_readable})
add_executable(wptr_accessor_chain_test_setAccessor ${wptr_accessor_chain_test_setAccessor})


#wptr_accessor_wrap tests

add_executable(wptr_accessor_wrap_test_access ${wptr_accessor_wrap_test_access})
add_executable(wptr_accessor_wrap_test_assignment ${wptr_accessor_wrap_test_assignment})
add_executable(wptr_accessor_wrap_test_comparison ${wptr_accessor_wrap_test_comparison})
add_executable(wptr_accessor_wrap_test_constructor ${wptr_accessor_wrap_test_constructor})
add_executable(wptr_accessor_wrap_test_constructor_base_readable ${wptr_accessor_wrap_test_constructor_base_readable})
add_executable(wptr_accessor_wrap_test_constructor_copy ${wptr_accessor_wrap_test_constructor_copy})
add_executable(wptr_accessor_wrap_test_constructor_readable ${wptr_accessor_wrap_test_constructor_readable})


#wptr_wrapped tests
add_executable(wptr_wrapped_test_assignment ${wptr_wrapped_test_assignment})
add_executable(wptr_wrapped_test_constructor ${wptr_wrapped_test_constructor})
add_executable(wptr_wrapped_test_constructor_object ${wptr_wrapped_test_constructor_object})
add_executable(wptr_wrapped_test_constructor_base_readable ${wptr_wrapped_test_constructor_base_readable})
add_executable(wptr_wrapped_test_constructor_base_readable_readable ${wptr_wrapped_test_constructor_base_readable_readable})
add_executable(wptr_wrapped_test_constructor_copy ${wptr_wrapped_test_constructor_copy})
add_executable(wptr_wrapped_test_constructor_object_readable ${wptr_wrapped_test_constructor_object_readable})
add_executable(wptr_wrapped_test_member_access ${wptr_wrapped_test_member_access})


#wptr_wrapped tests
add_executable(wptr_complex_test_assignment ${wptr_complex_test_assignment})
add_executable(wptr_complex_test_assignment_base_readable ${wptr_complex_test_assignment_base_readable})
add_executable(wptr_complex_test_comparison ${wptr_complex_test_comparison})
add_executable(wptr_complex_test_constructor ${wptr_complex_test_constructor})
add_executable(wptr_complex_test_constructor_base_readable_accessor ${wptr_complex_test_constructor_base_readable_accessor})
add_executable(wptr_complex_test_constructor_base_readable_base_readable ${wptr_complex_test_constructor_base_readable_base_readable})
add_executable(wptr_complex_test_constructor_base_readable_readable ${wptr_complex_test_constructor_base_readable_readable})
add_executable(wptr_complex_test_constructor_copy ${wptr_complex_test_constructor_copy})
add_executable(wptr_complex_test_constructor_obj_accessor ${wptr_complex_test_constructor_obj_accessor})
add_executable(wptr_complex_test_constructor_obj_base_readable ${wptr_complex_test_constructor_obj_base_readable})
add_executable(wptr_complex_test_constructor_obj_readable ${wptr_complex_test_constructor_obj_readable})
add_executable(wptr_complex_test_duplicate ${wptr_complex_test_duplicate})
add_executable(wptr_complex_test_empty ${wptr_complex_test_empty})
add_executable(wptr_complex_test_getAccessor ${wptr_complex_test_getAccessor})
add_executable(wptr_complex_test_member_access ${wptr_complex_test_member_access})
add_executable(wptr_complex_test_reference ${wptr_complex_test_reference})
add_executable(wptr_complex_test_setAccessor_base_readable ${wptr_complex_test_setAccessor_base_readable})
add_executable(wptr_complex_test_setAccessor_readable ${wptr_complex_test_setAccessor_readable})


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


#wptr_simple tests

add_test(NAME wptr_simple_constructor COMMAND wptr_simple_test_constructor)
add_test(NAME wptr_simple_constructor_copy COMMAND wptr_simple_test_constructor_copy)
add_test(NAME wptr_simple_assignment COMMAND wptr_simple_test_assignment)
add_test(NAME wptr_simple_reference COMMAND wptr_simple_test_reference)
add_test(NAME wptr_simple_member_access COMMAND wptr_simple_test_member_access)
add_test(NAME wptr_simple_comparison COMMAND wptr_simple_test_comparison)
add_test(NAME wptr_simple_duplicate COMMAND wptr_simple_test_duplicate)


#wptr_inheritance tests

add_test(NAME wptr_inheritance_constructor COMMAND wptr_inheritance_test_constructor)
add_test(NAME wptr_inheritance_constructor_copy COMMAND wptr_inheritance_test_constructor_copy)
add_test(NAME wptr_inheritance_assignment COMMAND wptr_inheritance_test_assignment)
add_test(NAME wptr_inheritance_reference COMMAND wptr_inheritance_test_reference)
add_test(NAME wptr_inheritance_member_access COMMAND wptr_inheritance_test_member_access)
add_test(NAME wptr_inheritance_comparison COMMAND wptr_inheritance_test_comparison)
add_test(NAME wptr_inheritance_duplicate COMMAND wptr_inheritance_test_duplicate)


#wptr_itr tests

add_test(NAME wptr_itr_constructor COMMAND wptr_itr_test_constructor)
add_test(NAME wptr_itr_constructor_copy COMMAND wptr_itr_test_constructor_copy)
add_test(NAME wptr_itr_assignment COMMAND wptr_itr_test_assignment)
add_test(NAME wptr_itr_reference COMMAND wptr_itr_test_reference)
add_test(NAME wptr_itr_member_access COMMAND wptr_itr_test_member_access)
add_test(NAME wptr_itr_comparison COMMAND wptr_itr_test_comparison)
add_test(NAME wptr_itr_duplicate COMMAND wptr_itr_test_duplicate)


#wptr_dereference_accessor tests

add_test(NAME wptr_dereference_accessor_access COMMAND wptr_dereference_accessor_test_access)
add_test(NAME wptr_dereference_accessor_constructor COMMAND wptr_dereference_accessor_test_constructor)
add_test(NAME wptr_dereference_accessor_constructor_copy COMMAND wptr_dereference_accessor_test_constructor_copy)
add_test(NAME wptr_dereference_accessor_assignment COMMAND wptr_dereference_accessor_test_assignment)


#wptr_no_accessor tests

add_test(NAME wptr_no_accessor_access COMMAND wptr_no_accessor_test_access)
add_test(NAME wptr_no_accessor_constructor COMMAND wptr_no_accessor_test_constructor)
add_test(NAME wptr_no_accessor_constructor_copy COMMAND wptr_no_accessor_test_constructor_copy)
add_test(NAME wptr_no_accessor_assignment COMMAND wptr_no_accessor_test_assignment)


#wptr_inheritance_accessor tests

add_test(NAME wptr_inheritance_accessor_access COMMAND wptr_inheritance_accessor_test_access)
add_test(NAME wptr_inheritance_accessor_constructor COMMAND wptr_inheritance_accessor_test_constructor)
add_test(NAME wptr_inheritance_accessor_constructor_copy COMMAND wptr_inheritance_accessor_test_constructor_copy)
add_test(NAME wptr_inheritance_accessor_assignment COMMAND wptr_inheritance_accessor_test_assignment)


#wptr_itr_accessor tests

add_test(NAME wptr_itr_accessor_constructor COMMAND wptr_itr_accessor_test_constructor)
add_test(NAME wptr_itr_accessor_constructor_copy COMMAND wptr_itr_accessor_test_constructor_copy)
add_test(NAME wptr_itr_accessor_assignment COMMAND wptr_itr_accessor_test_assignment)
add_test(NAME wptr_itr_accessor_access COMMAND wptr_itr_accessor_test_access)
add_test(NAME wptr_itr_accessor_comparison COMMAND wptr_itr_accessor_test_comparison)


#wptr_offset_accessor tests

add_test(NAME wptr_offset_accessor_constructor COMMAND wptr_offset_accessor_test_constructor)
add_test(NAME wptr_offset_accessor_constructor_copy COMMAND wptr_offset_accessor_test_constructor_copy)
add_test(NAME wptr_offset_accessor_assignment COMMAND wptr_offset_accessor_test_assignment)
add_test(NAME wptr_offset_accessor_access COMMAND wptr_offset_accessor_test_access)
add_test(NAME wptr_offset_accessor_comparison COMMAND wptr_offset_accessor_test_comparison)


#wptr_accessor_chain tests

add_test(NAME wptr_accessor_chain_access COMMAND wptr_accessor_chain_test_access)
add_test(NAME wptr_accessor_chain_assignment COMMAND wptr_accessor_chain_test_assignment)
add_test(NAME wptr_accessor_chain_constructor COMMAND wptr_accessor_chain_test_constructor)
add_test(NAME wptr_accessor_chain_constructor_base_readable COMMAND wptr_accessor_chain_test_constructor_base_readable)
add_test(NAME wptr_accessor_chain_constructor_copy COMMAND wptr_accessor_chain_test_constructor_copy)
add_test(NAME wptr_accessor_chain_constructor_readable COMMAND wptr_accessor_chain_test_constructor_readable)
add_test(NAME wptr_accessor_chain_setAccessor COMMAND wptr_accessor_chain_test_setAccessor)


#wptr_accessor_wrap tests

add_test(NAME wptr_accessor_wrap_access COMMAND wptr_accessor_wrap_test_access)
add_test(NAME wptr_accessor_wrap_assignment COMMAND wptr_accessor_wrap_test_assignment)
add_test(NAME wptr_accessor_wrap_comparison COMMAND wptr_accessor_wrap_test_comparison)
add_test(NAME wptr_accessor_wrap_constructor COMMAND wptr_accessor_wrap_test_constructor)
add_test(NAME wptr_accessor_wrap_constructor_base_readable COMMAND wptr_accessor_wrap_test_constructor_base_readable)
add_test(NAME wptr_accessor_wrap_constructor_copy COMMAND wptr_accessor_wrap_test_constructor_copy)
add_test(NAME wptr_accessor_wrap_constructor_readable COMMAND wptr_accessor_wrap_test_constructor_readable)


#wptr_accessor_wrap tests

add_test(NAME wptr_wrapped_assignment COMMAND wptr_wrapped_test_assignment)
add_test(NAME wptr_wrapped_constructor COMMAND wptr_wrapped_test_constructor)
add_test(NAME wptr_wrapped_constructor_object COMMAND wptr_wrapped_test_constructor_object)
add_test(NAME wptr_wrapped_constructor_base_readable COMMAND wptr_wrapped_test_constructor_base_readable)
add_test(NAME wptr_wrapped_constructor_base_readable_readable COMMAND wptr_wrapped_test_constructor_base_readable_readable)
add_test(NAME wptr_wrapped_constructor_copy COMMAND wptr_wrapped_test_constructor_copy)
add_test(NAME wptr_wrapped_constructor_object_readable COMMAND wptr_wrapped_test_constructor_object_readable)
add_test(NAME wptr_wrapped_member_access COMMAND wptr_wrapped_test_member_access)


#wptr_accessor_wrap tests

add_test(NAME wptr_complex_test_assignment COMMAND wptr_complex_test_assignment)
add_test(NAME wptr_complex_test_assignment_base_readable COMMAND wptr_complex_test_assignment_base_readable)
add_test(NAME wptr_complex_test_comparison COMMAND wptr_complex_test_comparison)
add_test(NAME wptr_complex_test_constructor COMMAND wptr_complex_test_constructor)
add_test(NAME wptr_complex_test_constructor_base_readable_accessor COMMAND wptr_complex_test_constructor_base_readable_accessor)
add_test(NAME wptr_complex_test_constructor_base_readable_base_readable COMMAND wptr_complex_test_constructor_base_readable_base_readable)
add_test(NAME wptr_complex_test_constructor_base_readable_readable COMMAND wptr_complex_test_constructor_base_readable_readable)
add_test(NAME wptr_complex_test_constructor_copy COMMAND wptr_complex_test_constructor_copy)
add_test(NAME wptr_complex_test_constructor_obj_accessor COMMAND wptr_complex_test_constructor_obj_accessor)
add_test(NAME wptr_complex_test_constructor_obj_base_readable COMMAND wptr_complex_test_constructor_obj_base_readable)
add_test(NAME wptr_complex_test_constructor_obj_readable COMMAND wptr_complex_test_constructor_obj_readable)
add_test(NAME wptr_complex_test_duplicate COMMAND wptr_complex_test_duplicate)
add_test(NAME wptr_complex_test_empty COMMAND wptr_complex_test_empty)
add_test(NAME wptr_complex_test_getAccessor COMMAND wptr_complex_test_getAccessor)
add_test(NAME wptr_complex_test_member_access COMMAND wptr_complex_test_member_access)
add_test(NAME wptr_complex_test_reference COMMAND wptr_complex_test_reference)
add_test(NAME wptr_complex_test_setAccessor_base_readable COMMAND wptr_complex_test_setAccessor_base_readable)
add_test(NAME wptr_complex_test_setAccessor_readable COMMAND wptr_complex_test_setAccessor_readable)

#wmptr tests

add_test(NAME wmptr_test_assignment COMMAND wmptr_test_assignment)
add_test(NAME wmptr_test_constructor COMMAND wmptr_test_constructor)
add_test(NAME wmptr_test_constructor_copy COMMAND wmptr_test_constructor_copy)
add_test(NAME wmptr_test_member_access COMMAND wmptr_test_member_access)
add_test(NAME wmptr_test_reference COMMAND wmptr_test_reference)
add_test(NAME wmptr_test_setObject COMMAND wmptr_test_setObject)
add_test(NAME wmptr_test_setOffset COMMAND wmptr_test_setOffset)

install(TARGETS wise_pointers RUNTIME DESTINATION bin)

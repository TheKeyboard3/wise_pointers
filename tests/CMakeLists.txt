cmake_minimum_required(VERSION 3.0)

#wptr_managed tests
set(wptr_managed_tests
        wptr_managed_tests.h
        wptr_managed_tests.cpp
        ../wptr_managed.h
)
#wptr_simple tests
set(wptr_simple_tests
        wptr_simple_tests.h
        wptr_simple_tests.cpp
        ../wptr_simple.h
)
#wptr_inheritance tests
set(wptr_inheritance_tests
        wptr_inheritance_tests.h
        wptr_inheritance_tests.cpp
        ../wptr_inheritance.h
)
#wptr_itr tests
set(wptr_itr_tests
        wptr_itr_tests.h
        wptr_itr_tests.cpp
        ../wptr_itr.h
)
#wptr_dereference_accessor tests
set(wptr_dereference_accessor_tests
        wptr_dereference_accessor_tests.h
        wptr_dereference_accessor_tests.cpp
        ../wptr_dereference_accessor.h
)
#wptr_no_accessor tests
set(wptr_no_accessor_tests
        wptr_no_accessor_tests.h
        wptr_no_accessor_tests.cpp
        ../wptr_no_accessor.h
)
#wptr_inheritance_accessor tests
set(wptr_inheritance_accessor_tests
        wptr_inheritance_accessor_tests.h
        wptr_inheritance_accessor_tests.cpp
        ../wptr_inheritance_accessor.h
)
#wptr_itr_accessor tests
set(wptr_itr_accessor_tests
        wptr_itr_accessor_tests.h
        wptr_itr_accessor_tests.cpp
        ../wptr_itr_accessor.h
)
#wptr_offset_accessor tests
set(wptr_offset_accessor_tests
        wptr_offset_accessor_tests.h
        wptr_offset_accessor_tests.cpp
        ../wptr_offset_accessor.h
)
#wptr_accessor_chain tests
set(wptr_accessor_chain_tests
        wptr_accessor_chain_tests.h
        wptr_accessor_chain_tests.cpp
        ../wptr_accessor_chain.h
)
#wptr_accessor_wrap tests
set(wptr_accessor_wrap_tests
        wptr_accessor_wrap_tests.h
        wptr_accessor_wrap_tests.cpp
        ../wptr_accessor_wrap.h
)
#wptr_wrapped tests
set(wptr_wrapped_tests
        wptr_wrapped_tests.h
        wptr_wrapped_tests.cpp
        ../wptr_wrapped.h
)
#wptr_complex tests
set(wptr_complex_tests
        wptr_complex_tests.h
        wptr_complex_tests.cpp
        ../wptr_complex.h
)
project(wise_pointers)

include(CTest)

#test executables

#wptr_managed tests
add_executable(wptr_managed_tests EXCLUDE_FROM_ALL ${wptr_managed_tests})

#wptr_simple tests
add_executable(wptr_simple_tests EXCLUDE_FROM_ALL ${wptr_simple_tests})

#wptr_inheritance tests
add_executable(wptr_inheritance_tests EXCLUDE_FROM_ALL ${wptr_inheritance_tests})

#wptr_itr tests
add_executable(wptr_itr_tests EXCLUDE_FROM_ALL ${wptr_itr_tests})

#wptr_dereference_accessor tests
add_executable(wptr_dereference_accessor_tests EXCLUDE_FROM_ALL ${wptr_dereference_accessor_tests})

#wptr_no_accessor tests
add_executable(wptr_no_accessor_tests EXCLUDE_FROM_ALL ${wptr_no_accessor_tests})

#wptr_inheritance_accessor tests
add_executable(wptr_inheritance_accessor_tests EXCLUDE_FROM_ALL ${wptr_inheritance_accessor_tests})

#wptr_itr_accessor tests
add_executable(wptr_itr_accessor_tests EXCLUDE_FROM_ALL ${wptr_itr_accessor_tests})

#wptr_offset_accessor tests
add_executable(wptr_offset_accessor_tests EXCLUDE_FROM_ALL ${wptr_offset_accessor_tests})

#wptr_accessor_chain tests
add_executable(wptr_accessor_chain_tests EXCLUDE_FROM_ALL ${wptr_accessor_chain_tests})

#wptr_accessor_wrap tests
add_executable(wptr_accessor_wrap_tests EXCLUDE_FROM_ALL ${wptr_accessor_wrap_tests})

#wptr_wrapped tests
add_executable(wptr_wrapped_tests EXCLUDE_FROM_ALL ${wptr_wrapped_tests})

#wptr_complex tests
add_executable(wptr_complex_tests EXCLUDE_FROM_ALL ${wptr_complex_tests})


#tests

#wptr_managed tests
add_test(NAME wptr_managed_constructor COMMAND wptr_managed_tests wptr_managed_test_constructor)
add_test(NAME wptr_managed_constructor_copy COMMAND wptr_managed_tests wptr_managed_test_constructor_copy)
add_test(NAME wptr_managed_reference COMMAND wptr_managed_tests wptr_managed_test_reference)
add_test(NAME wptr_managed_member_access COMMAND wptr_managed_tests wptr_managed_test_member_access)

#wptr_simple tests
add_test(NAME wptr_simple_constructor COMMAND wptr_simple_tests wptr_simple_test_constructor)
add_test(NAME wptr_simple_constructor_copy COMMAND wptr_simple_tests wptr_simple_test_constructor_copy)
add_test(NAME wptr_simple_assignment COMMAND wptr_simple_tests wptr_simple_test_assignment)
add_test(NAME wptr_simple_reference COMMAND wptr_simple_tests wptr_simple_test_reference)
add_test(NAME wptr_simple_member_access COMMAND wptr_simple_tests wptr_simple_test_member_access)
add_test(NAME wptr_simple_comparison COMMAND wptr_simple_tests wptr_simple_test_comparison)
add_test(NAME wptr_simple_duplicate COMMAND wptr_simple_tests wptr_simple_test_duplicate)

#wptr_inheritance tests
add_test(NAME wptr_inheritance_constructor COMMAND wptr_inheritance_tests wptr_inheritance_test_constructor)
add_test(NAME wptr_inheritance_constructor_copy COMMAND wptr_inheritance_tests wptr_inheritance_test_constructor_copy)
add_test(NAME wptr_inheritance_assignment COMMAND wptr_inheritance_tests wptr_inheritance_test_assignment)
add_test(NAME wptr_inheritance_reference COMMAND wptr_inheritance_tests wptr_inheritance_test_reference)
add_test(NAME wptr_inheritance_member_access COMMAND wptr_inheritance_tests wptr_inheritance_test_member_access)
add_test(NAME wptr_inheritance_comparison COMMAND wptr_inheritance_tests wptr_inheritance_test_comparison)
add_test(NAME wptr_inheritance_duplicate COMMAND wptr_inheritance_tests wptr_inheritance_test_duplicate)

#wptr_itr tests
add_test(NAME wptr_itr_constructor COMMAND wptr_itr_tests wptr_itr_test_constructor)
add_test(NAME wptr_itr_constructor_copy COMMAND wptr_itr_tests wptr_itr_test_constructor_copy)
add_test(NAME wptr_itr_assignment COMMAND wptr_itr_tests wptr_itr_test_assignment)
add_test(NAME wptr_itr_reference COMMAND wptr_itr_tests wptr_itr_test_reference)
add_test(NAME wptr_itr_member_access COMMAND wptr_itr_tests wptr_itr_test_member_access)
add_test(NAME wptr_itr_comparison COMMAND wptr_itr_tests wptr_itr_test_comparison)
add_test(NAME wptr_itr_duplicate COMMAND wptr_itr_tests wptr_itr_test_duplicate)

#wptr_dereference_accessor tests
add_test(NAME wptr_dereference_accessor_access COMMAND wptr_dereference_accessor_tests wptr_dereference_accessor_test_access)
add_test(NAME wptr_dereference_accessor_constructor COMMAND wptr_dereference_accessor_tests wptr_dereference_accessor_test_constructor)
add_test(NAME wptr_dereference_accessor_constructor_copy COMMAND wptr_dereference_accessor_tests wptr_dereference_accessor_test_constructor_copy)
add_test(NAME wptr_dereference_accessor_assignment COMMAND wptr_dereference_accessor_tests wptr_dereference_accessor_test_assignment)

#wptr_no_accessor tests
add_test(NAME wptr_no_accessor_access COMMAND wptr_no_accessor_tests wptr_no_accessor_test_access)
add_test(NAME wptr_no_accessor_constructor COMMAND wptr_no_accessor_tests wptr_no_accessor_test_constructor)
add_test(NAME wptr_no_accessor_constructor_copy COMMAND wptr_no_accessor_tests wptr_no_accessor_test_constructor_copy)
add_test(NAME wptr_no_accessor_assignment COMMAND wptr_no_accessor_tests wptr_no_accessor_test_assignment)

#wptr_inheritance_accessor tests
add_test(NAME wptr_inheritance_accessor_access COMMAND wptr_inheritance_accessor_tests wptr_inheritance_accessor_test_access)
add_test(NAME wptr_inheritance_accessor_constructor COMMAND wptr_inheritance_accessor_tests wptr_inheritance_accessor_test_constructor)
add_test(NAME wptr_inheritance_accessor_constructor_copy COMMAND wptr_inheritance_accessor_tests wptr_inheritance_accessor_test_constructor_copy)
add_test(NAME wptr_inheritance_accessor_assignment COMMAND wptr_inheritance_accessor_tests wptr_inheritance_accessor_test_assignment)

#wptr_itr_accessor tests
add_test(NAME wptr_itr_accessor_constructor COMMAND wptr_itr_accessor_tests wptr_itr_accessor_test_constructor)
add_test(NAME wptr_itr_accessor_constructor_copy COMMAND wptr_itr_accessor_tests wptr_itr_accessor_test_constructor_copy)
add_test(NAME wptr_itr_accessor_assignment COMMAND wptr_itr_accessor_tests wptr_itr_accessor_test_assignment)
add_test(NAME wptr_itr_accessor_access COMMAND wptr_itr_accessor_tests wptr_itr_accessor_test_access)
add_test(NAME wptr_itr_accessor_comparison COMMAND wptr_itr_accessor_tests wptr_itr_accessor_test_comparison)

#wptr_offset_accessor tests
add_test(NAME wptr_offset_accessor_constructor COMMAND wptr_offset_accessor_tests wptr_offset_accessor_test_constructor)
add_test(NAME wptr_offset_accessor_constructor_copy COMMAND wptr_offset_accessor_tests wptr_offset_accessor_test_constructor_copy)
add_test(NAME wptr_offset_accessor_assignment COMMAND wptr_offset_accessor_tests wptr_offset_accessor_test_assignment)
add_test(NAME wptr_offset_accessor_access COMMAND wptr_offset_accessor_tests wptr_offset_accessor_test_access)
add_test(NAME wptr_offset_accessor_comparison COMMAND wptr_offset_accessor_tests wptr_offset_accessor_test_comparison)

#wptr_accessor_chain tests
add_test(NAME wptr_accessor_chain_t COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_access)
add_test(NAME wptr_accessor_chain_assignment COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_assignment)
add_test(NAME wptr_accessor_chain_constructor COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_constructor)
add_test(NAME wptr_accessor_chain_constructor_base_readable COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_constructor_base_readable)
add_test(NAME wptr_accessor_chain_constructor_copy COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_constructor_copy)
add_test(NAME wptr_accessor_chain_constructor_readable COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_constructor_readable)
add_test(NAME wptr_accessor_chain_setAccessor COMMAND wptr_accessor_chain_tests wptr_accessor_chain_test_setAccessor)

#wptr_accessor_wrap tests
add_test(NAME wptr_accessor_wrap_access COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_access)
add_test(NAME wptr_accessor_wrap_assignment COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_assignment)
add_test(NAME wptr_accessor_wrap_comparison COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_comparison)
add_test(NAME wptr_accessor_wrap_constructor COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_constructor)
add_test(NAME wptr_accessor_wrap_constructor_base_readable COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_constructor_base_readable)
add_test(NAME wptr_accessor_wrap_constructor_copy COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_constructor_copy)
add_test(NAME wptr_accessor_wrap_constructor_readable COMMAND wptr_accessor_wrap_tests wptr_accessor_wrap_test_constructor_readable)

#wptr_wrapped tests
add_test(NAME wptr_wrapped_assignment COMMAND wptr_wrapped_tests wptr_wrapped_test_assignment)
add_test(NAME wptr_wrapped_constructor COMMAND wptr_wrapped_tests wptr_wrapped_test_constructor)
add_test(NAME wptr_wrapped_constructor_object COMMAND wptr_wrapped_tests wptr_wrapped_test_constructor_object)
add_test(NAME wptr_wrapped_constructor_base_readable COMMAND wptr_wrapped_tests wptr_wrapped_test_constructor_base_readable)
add_test(NAME wptr_wrapped_constructor_base_readable_readable COMMAND wptr_wrapped_tests wptr_wrapped_test_constructor_base_readable_readable)
add_test(NAME wptr_wrapped_constructor_copy COMMAND wptr_wrapped_tests wptr_wrapped_test_constructor_copy)
add_test(NAME wptr_wrapped_constructor_object_readable COMMAND wptr_wrapped_tests wptr_wrapped_test_constructor_object_readable)
add_test(NAME wptr_wrapped_member_access COMMAND wptr_wrapped_tests wptr_wrapped_test_member_access)

#wptr_complex tests
add_test(NAME wptr_complex_assignment COMMAND wptr_complex_tests wptr_complex_test_assignment)
add_test(NAME wptr_complex_assignment_base_readable COMMAND wptr_complex_tests wptr_complex_test_assignment_base_readable)
add_test(NAME wptr_complex_comparison COMMAND wptr_complex_tests wptr_complex_test_comparison)
add_test(NAME wptr_complex_constructor COMMAND wptr_complex_tests wptr_complex_test_constructor)
add_test(NAME wptr_complex_constructor_base_readable_accessor COMMAND wptr_complex_tests wptr_complex_test_constructor_base_readable_accessor)
add_test(NAME wptr_complex_constructor_base_readable_base_readable COMMAND wptr_complex_tests wptr_complex_test_constructor_base_readable_base_readable)
add_test(NAME wptr_complex_constructor_base_readable_readable COMMAND wptr_complex_tests wptr_complex_test_constructor_base_readable_readable)
add_test(NAME wptr_complex_constructor_copy COMMAND wptr_complex_tests wptr_complex_test_constructor_copy)
add_test(NAME wptr_complex_constructor_obj_accessor COMMAND wptr_complex_tests wptr_complex_test_constructor_obj_accessor)
add_test(NAME wptr_complex_constructor_obj_base_readable COMMAND wptr_complex_tests wptr_complex_test_constructor_obj_base_readable)
add_test(NAME wptr_complex_constructor_obj_readable COMMAND wptr_complex_tests wptr_complex_test_constructor_obj_readable)
add_test(NAME wptr_complex_duplicate COMMAND wptr_complex_tests wptr_complex_test_duplicate)
add_test(NAME wptr_complex_empty COMMAND wptr_complex_tests wptr_complex_test_empty)
add_test(NAME wptr_complex_getAccessor COMMAND wptr_complex_tests wptr_complex_test_getAccessor)
add_test(NAME wptr_complex_member_access COMMAND wptr_complex_tests wptr_complex_test_member_access)
add_test(NAME wptr_complex_reference COMMAND wptr_complex_tests wptr_complex_test_reference)
add_test(NAME wptr_complex_setAccessor_base_readable COMMAND wptr_complex_tests wptr_complex_test_setAccessor_base_readable)
add_test(NAME wptr_complex_setAccessor_readable COMMAND wptr_complex_tests wptr_complex_test_setAccessor_readable)

#install


#test
add_custom_target(build_and_test COMMAND ${CMAKE_CTEST_COMMAND})

add_dependencies(build_and_test wptr_managed_tests
        wptr_simple_tests
        wptr_inheritance_tests
        wptr_itr_tests
        wptr_dereference_accessor_tests
        wptr_no_accessor_tests
        wptr_inheritance_accessor_tests
        wptr_itr_accessor_tests
        wptr_offset_accessor_tests
        wptr_accessor_chain_tests
        wptr_accessor_wrap_tests
        wptr_wrapped_tests
        wptr_complex_tests
)

cmake_minimum_required(VERSION 3.0)

add_subdirectory(tests)

#install headers
set(wise_pointers
        awptr_managed.h
        wptr_accessor.h
        wptr_accessor_chain.h
        wptr_accessor_wrap.h
        wptr_accessor_wrap_readable.h
        wptr_agnostic.h
        wptr_arr_manager.h
        wptr_base_readable.h
        wptr_complex.h
        wptr_dereference_accessor.h
        wptr_inheritance.h
        wptr_inheritance_accessor.h
        wptr_itr.h
        wptr_itr_accessor.h
        wptr_itr_tests.h
        wptr_managed.h
        wptr_no_accessor.h
        wptr_offset_accessor.h
        wptr_readable.h
        wptr_simple.h
        wptr_wrapped.h
        wptr_writable.h
)

project(wise_pointers)

#install

install_files(wise_pointers DESTINATION include)

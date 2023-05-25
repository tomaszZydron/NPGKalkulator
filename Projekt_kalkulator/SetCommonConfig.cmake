message(STATUS "PROJECT: ${PROJECT_ID}")
project(${PROJECT_ID})

# Ustaw standard języka C.
set(CMAKE_C_STANDARD 11)  # dostępne wartości: 90, 99, 11

# Ustaw standard języka C++.
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)

# Skorzystaj z narzędzia AddressSanitizer (pozwalającego wykryć m.in. błędy pisania
# po nie-swojej pamięci statycznej). Narzędzie jest dostępne natywnie dla systemów
# operacyjnych z rodziny UNIX.
# REF: https://gcc.gnu.org/gcc-4.8/changes.html
# Jeśli nie chcesz skorzystać z tego narzędzia, zakomentuj poniższą linię.
set(USE_ASAN false)
if ((DEFINED USE_ASAN) AND (USE_ASAN STREQUAL "true"))
    message(STATUS "Using AddressSanitizer (ASan).")
    if (UNIX)
        # message(STATUS "ASAN_OPTIONS = $ENV{ASAN_OPTIONS}")
        # set(ENV{ASAN_OPTIONS} allocator_may_return_null=1)
        add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address)
    endif(UNIX)
endif()

include_directories(include)

set(EXEC_DEBUG ${PROJECT_ID}__debug)

if(EXISTS ${PROJECT_SOURCE_DIR}/main.c)
    set(lang_src_extension c)
else()
    set(lang_src_extension cpp)
endif()

add_executable(${EXEC_DEBUG} ${SOURCE_FILES} main.${lang_src_extension})

if(EXISTS ${PROJECT_SOURCE_DIR}/test)
    set(EXEC_TEST ${PROJECT_ID}__test)
    add_executable(${EXEC_TEST} ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

    # == Uwzględnij pliki frameworku Google Testing Framework (GTF) ==

    # Przyjmij, że główny katalog z plikami frameworku GTF znajduje się
    # dwa katalogi wyżej względem katalogu projektu.
    set(GTEST_ROOT ../../googletest-master)

    # Dodaj katalogi z plikami nagłówkowymi GTF.
    target_include_directories(${EXEC_TEST} PUBLIC
            ${GTEST_ROOT}/googlemock/include
            ${GTEST_ROOT}/googletest/include
            )

    add_subdirectory(${GTEST_ROOT} googletest-master)

    # Dołącz bibliotekę Google Mock.
    target_link_libraries(${EXEC_TEST} gmock)
endif()


#set(CMAKE_VERBOSE_MAKEFILE ON)

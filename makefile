.PHONY: dirs clean

all: dirs ut_main create_html_report move_the_files_to_report_folder

ut_main: test/ut.cpp test/ut_rectangle.h test/ut_ellipse.h
	g++ -pg -fprofile-arcs -ftest-coverage test/ut.cpp -o bin/ut_main -lgtest -lpthread
	bin/ut_main

create_html_report:  test/ut.cpp
	gcov -c -b ut.cpp
	lcov -c -o ut.info -d . --rc lcov_branch_coverage=1
	genhtml ut.info -o report --branch-coverage

move_the_files_to_report_folder: ut.gcda gmon.out ut.gcno ut.info
	mv ut.gcda ./report/ut.gcda
	mv gmon.out ./report/gmon.out
	mv ut.gcno ./report/ut.gcno
	mv ut.info ./report/ut.info

open_report:
	firefox ./report/src/index.html
dirs:
	mkdir -p bin
	mkdir -p report

clean:
	rm -rf bin/*
	rm -rf report/*

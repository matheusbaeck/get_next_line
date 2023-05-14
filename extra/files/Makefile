NAME = file0.txt \
	file1.txt \
	file2.txt \
	file3.txt \
	file4.txt \
	file5.txt \
	file6.txt \
	file7.txt \
	file8.txt \
	file9.txt \
	file11.txt \
	file12.txt \

NAME_EXIT = $(NAME:.txt=_exit.txt)

NAME_DIFF = $(NAME:.txt=_diff.txt)

all: clean $(NAME_EXIT)

%_exit.txt: %.txt
	touch $@

%_diff.txt: %.txt
	diff $< $(<:.txt=_exit.txt) > $@ 

clean:
	rm -rf $(NAME_EXIT) $(NAME_DIFF)

diff: $(NAME_DIFF)

	
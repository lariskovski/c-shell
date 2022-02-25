SOURCEFILE=code.c
OUTPUTFILE=code

build: $(SOURCEFILE)
	@gcc $(SOURCEFILE) -o $(OUTPUTFILE) -lreadline
	@echo "Compiled Successfully!"

run: $(OUTPUTFILE)
	@ ./$(OUTPUTFILE)

clean:
	@rm -rf $(OUTPUTFILE) && echo "Removed '$(OUTPUTFILE)' file"
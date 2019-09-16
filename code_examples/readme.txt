The code_examples directory contains a collection of examples that will be built automatically by a jenkins job for each compiler available in the build_system/tools/Compilers directory.
Every example in this folder MUST be created and exported by the Aurix-IDE through "File>New>Aurix project" and "File>Export..".
In the directory are also present the following batch files:

	 - build_all.bat: 
		this batch scans the code_example directory in order to find examples to be built. Then, the script starts building each example found.

	 - build_new_or_updated_examples.bat:
		this batch scans the code_example directory and build new examples or examples that have been updated only.

	 - clean_all.bat: 
		this batch removes all the files created by building a project (calls a make clean for each project).

	 - generate_report.bat: 
		this batch scans the code_example directory to find examples and their relative built files. 
		The script then creates a report (report.html) inside the code_example directory to summarize which examples have been successfully built.
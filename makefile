build:
	gcc  free.c  help.c  history.c  matcher.c  open_files.c  print_help.c   prompt.c  run_path.c  strings.c   tokenizer.c  enviroment.c  tools.c -o my_shell -g
	valgrind --leak-check=full --show-leak-kinds=all ./my_shell

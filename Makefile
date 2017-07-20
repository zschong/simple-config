CC:=gcc

test-config: test-config.c config-file.c config-field.c
	$(CC) $+ -o $@

clean:
	@rm -rfv test-config

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define END "\033[0m"

int		timeout_ms = 3000;
char	*prog_name = "./rush01_test";

char	*get_next_line(int fd);

void free_array(char **arr, int nb)
{
	int i = 0;
	
	while (i < nb)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_int_array(int **arr, int nb)
{
	int i = 0;
	
	while (i < nb)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char *add_char(char *str, char c)
{
	int i = 0;
	while (str[i])
		i++;
	str[i] = ' ';
	str[i + 1] = c;
	return str;
}

char *get_cols(int **matrix, char *res, int reverse, int len)
{
	int col = 0;
	int biggest = 0;
	int point = 0;
	int row;

	while (col <= len - 1 && col >= 0)
	{
		biggest = 0;
		point = 0;
		row = reverse == -1 ? len - 1 : 0;
		while (row <= len - 1 && row >= 0)
		{
			if (matrix[row][col] > biggest)
			{
				point++;
				biggest = matrix[row][col];
			}
			if (reverse == -1)
				row--;
			else
				row++;
		}
		res = add_char(res, point + '0');
		col++;
	}
	return res;
}

char *get_rows(int **matrix, char *res, int reverse, int len)
{
	int col;
	int row = 0;
	int biggest = 0;
	int point = 0;

	while (row <= len - 1 && row >= 0)
	{
		biggest = 0;
		point = 0;
		col = reverse == -1 ? len - 1 : 0;
		while (col <= len - 1 && col >= 0)
		{
			if (matrix[row][col] > biggest)
			{
				point++;
				biggest = matrix[row][col];
			}
			if (reverse == -1)
				col--;
			else
				col++;
		}
		res = add_char(res, point + '0');
		row++;
	}
	return res;
}

char *check_solution(char **str, char *err_msg)
{
	int len;
	int **matrix;
	char *result;
	int i;

	if (str == NULL || str[0] == NULL)
		return NULL;
	len = strlen(str[0]);
	for (i = 1; i < (len + 1) / 2; ++i)
	{
		if (str[i] == NULL || (int)strlen(str[i]) != len)
			return NULL;
	}
	if (str[i] != NULL)
		return NULL;

	len = (len + 1) / 2;
	matrix = malloc(sizeof(int *) * len);
	for (int i = 0; i < len; i++)
	{
		matrix[i] = malloc(sizeof(int) * len);
		for (int j = 0; j < len * 2; j += 2)
		{
			if (str[i][j] < '1' || str[i][j] > len + '0')
				sprintf(err_msg, "found invalid digit %c", str[i][j]);
			matrix[i][j / 2] = str[i][j] - '0';
		}
	}
	result = malloc(sizeof(char) * (len * 8 + 1));
	bzero(result, len * 8 + 1);
	get_cols(matrix, result, 1, len);
	get_cols(matrix, result, -1, len);
	get_rows(matrix, result, 1, len);
	get_rows(matrix, result, -1, len);
	free_int_array(matrix, len);
	memmove(result, result + 1, strlen(result));
	return result;
}

int	wait_for_process(pid_t pid)
{
	int	status;
	int	wait_res = 0;
	int	wait_time_ms = 0;

	while (1)
	{
		wait_res = waitpid(pid, &status, WNOHANG);
		if (wait_res > 0)
			break ;
		if (wait_res < 0)
		{
			perror("failed to wait for child process");
			exit(1);
		}
		if (wait_time_ms < timeout_ms)
			usleep(50000);
		else
		{
			kill(pid, SIGKILL);
			printf("⏰ %sTIMEOUT%s ", RED, WHITE);
			fflush(stdout);
			wait_res = waitpid(pid, &status, 0);
			break ;
		}
		wait_time_ms += 50;
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (0);
}

int write_tmp(char *arg)
{
	char *args[3];
	
	int pid;
	int	status;
	int tmp = open("res.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	args[0] = prog_name;
	args[1] = arg;
	args[2] = 0;
	pid = fork();
	if (pid == 0)
	{
		dup2(tmp, STDOUT_FILENO);
		dup2(tmp, STDERR_FILENO);
		close(tmp);
		execvp(prog_name, args);
		perror("execvp failed");
		exit(1);
	}
	close(tmp);
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	status = wait_for_process(pid);
	if (status)
		printf("💣 %sFAILED to execute with status code %i%s\n", RED, status, END);
	return status;
}

int get_output(char ***res)
{
	char *line = NULL;
	int tmp;
	char **result;
	int i = 0;

	tmp = open("res.tmp", O_RDONLY);
	result = calloc(10, sizeof(char *));
	while ((line = get_next_line(tmp)) != NULL)
	{
		if (i >= 10)
		{
			free_array(result, i);
			return 0;
		}
		result[i] = strdup(line);
		free(line);
		i++;
	}
	result[i] = 0;
	*res = result;
	close(tmp);
	usleep(1);
	remove("res.tmp");
	return i;
}

void print_wrong(char **res, char *expected, int test, char *arg)
{
	int i = -1;

	printf("%s❌ %d. %s \"%s\"\n%s", RED, test, prog_name, arg, END);
	printf("  %sYour output:\n%s", YELLOW, END);
	while (res[++i])
		printf("  %s", res[i]);
	fflush(stdout);
	printf("\n  %sExpected: %s%s\n", YELLOW, END, expected);
}

void print_ok(int test, char *arg)
{
	printf("%s✅ %d. %s \"%s\"\n%s", GREEN, test, prog_name, arg, END);
}

int test(char *arg, int *i)
{
	char 	**res;
	int 	len;
	char 	*solution = NULL;
	int 	success;
	char	err_msg[100] = "";

	*i += 1;
	success = !write_tmp(arg);
	len = get_output(&res);
	if (success)
	{
		solution = check_solution(res, err_msg);
		success = !*err_msg && solution && strcmp(solution, arg) == 0;
	}
	if (success == 0)
	{
		print_wrong(res, "a valid solution", *i, arg);
		if (*err_msg)
			printf("  %sError in solution: %s%s\n", YELLOW, END, err_msg);
		else if (solution)
			printf("  %sThis would be valid for %s%s\n", YELLOW, END, solution);
		else
			printf("  %sSolution is not a square!\n%s", YELLOW, END);
	}
	else
		print_ok(*i, arg);
	usleep(100000);
	free_array(res, len);
	free(solution);
	return (success);
}

int test_err(char *arg, int *i)
{
	char **res;
	int len;
	int success;

	*i += 1;
	success = !write_tmp(arg);
	len = get_output(&res);
	if (!success || !res[0] || strcmp(res[0], "Error\n") != 0 || res[1])
		success = 0;
	if (success == 0)
		print_wrong(res, "Error", *i, arg);
	else
		print_ok(*i, arg);
	usleep(100000);
	free_array(res, len);
	return success;
}

int	normal_test(int *tests)
{
	int success = 0;

	printf("%sValid inputs:%s\n", CYAN, END);
	success += test("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", tests);
	success += test("2 3 2 1 2 2 1 3 3 1 2 2 1 3 2 2", tests);
	success += test("3 1 2 2 1 3 2 2 2 2 3 1 2 1 2 3", tests);
	success += test("2 1 2 3 1 2 3 2 2 2 4 1 3 2 1 3", tests);
	success += test("2 4 2 1 2 1 2 4 3 3 1 2 1 2 3 3", tests);
	printf("%sNo solution:%s\n", CYAN, END);
	success += test_err("1 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", tests);
	success += test_err("2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2", tests);
	printf("%sInvalid input (to long):%s\n", CYAN, END);
	success += test_err("1 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 1", tests);
	success += test_err("1 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 1 3 4 1 2", tests);
	printf("%sInvalid input (to short):%s\n", CYAN, END);
	success += test_err("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2", tests);
	success += test_err("4 3 2 1 1 2 2 2 4 3 2 1", tests);
	printf("%sInvalid input (empty):%s\n", CYAN, END);
	success += test_err("", tests);
	printf("%sInvalid input (only spaces):%s\n", CYAN, END);
	success += test_err("               ", tests);
	printf("%sInvalid input (no spaces):%s\n", CYAN, END);
	success += test_err("4321122243211222", tests);
	printf("%sInvalid input (tabs instead spaces):%s\n", CYAN, END);
	success += test_err("2\t3\t2\t1\t1\t2\t2\t2\t4\t3\t2\t1\t1\t2\t2\t2", tests);
	printf("%sInvalid input (invalid number):%s\n", CYAN, END);
	success += test_err("a 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", tests);
	success += test_err("42 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", tests);
	success += test_err("-2 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", tests);
	success += test_err("0 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", tests);
	return (success);
}

int	bonus_1x1_tests(int *tests)
{
	int success = 0;

	success += test("1 1 1 1", tests);
	success += test_err("1 1 2 1", tests);
	success += test_err("1 1 1", tests);
	return (success);
}

char	*generate_input(int n, int offset, int impossible)
{
	char	err_msg[100] = "";
	char	*s;
	char	*solution;
	char	**matrix;
	int		i;

	if (n < 1 || n > 10)
		return (NULL);
	s = calloc(n * 2 + 1, sizeof(char));
	matrix = calloc(n + 1, sizeof(char *));
	i = -1;
	while (++i < n)
	{
		if (impossible)
			s[i * 2] = (offset % n) + 1 + '0';
		else
			s[i * 2] = ((i + offset) % n) + 1 + '0';
		if (s[i * 2] > '9')
			s[i * 2] = '9';
		s[i * 2 + 1] = ' ';
	}
	i = -1;
	while (++i < n)
	{
		matrix[i] = s;
		if (i + 1 != n)
		{
			s = strdup(matrix[i]);
			memmove(s + 2, s, n * 2 - 2);
			s[0] = matrix[i][n * 2 - 2];
		}
		matrix[i][n * 2 - 1] = '\0';
	}
	matrix[i] = NULL;
	solution = check_solution(matrix, err_msg);
	free_array(matrix, n);
	return (solution);
}

int	bonus_nxn_tests(int n, int *tests)
{
	int		success = 0;
	char	*solution;
	int		i;

	i = -1;
	while (++i < n && i < 4)
	{
		solution = generate_input(n, i, 0);
		success += test(solution, tests);
		free(solution);
	}
	switch (n) {
		case 5:
			success += test("3 1 3 3 2 3 3 1 2 2 2 2 1 3 2 2 1 3 2 3", tests);
			break;
		case 6:
			success += test("1 2 3 2 2 3 6 3 2 1 3 3 1 2 2 3 2 4 4 2 2 1 3 3", tests);
			break;
		case 7:
			success += test("2 1 4 5 3 4 2 4 3 2 2 3 1 2 2 1 2 4 4 3 5 2 4 3 1 2 4 2", tests);
			break;
		case 8:
			success += test("4 3 5 2 1 3 2 2 2 4 2 4 3 1 2 3 3 3 2 4 3 2 1 3 3 3 3 1 2 4 2 3", tests);
			break;
		case 9:
			success += test("4 1 2 2 4 3 3 3 3 3 3 5 2 1 2 3 2 4 2 2 3 4 1 2 2 3 3 5 3 4 1 6 2 2 2 4", tests);
			break;
	}
	solution = generate_input(n, 1, 1);
	success += test_err(solution, tests);
	free(solution);
	return (success);
}

int	bonus_10x10_tests(int *tests)
{
	int		success = 0;
	char	*solution;

	solution = generate_input(10, 1, 0);
	success += test_err(solution, tests);
	free(solution);
	return (success);
}

int	exec_tests_for(int n, int *tests)
{
	if (n == 10)
	{
		printf("%s=== Testing 10x10 (invalid) ===%s\n", PURPLE, END);
		return (bonus_10x10_tests(tests));
	}
	if (n < 1 || n > 9)
	{
		printf("Invalid value for n, must a number 1-9\n");
		exit(1);
	}
	printf("%s=== Testing %ix%i ===%s\n", PURPLE, n, n, END);
	if (n == 4)
		return (normal_test(tests));
	if (n == 1)
		return (bonus_1x1_tests(tests));
	return (bonus_nxn_tests(n, tests));
}

int main(int argc, char **argv)
{
	int tests = 0;
	int success = 0;
	int	bonus = 4;
	int	all = 0;
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (strcmp(argv[i], "-t") == 0)
		{
			if (++i != argc)
				timeout_ms = atoi(argv[i]);
		}
		else if (strcmp(argv[i], "-b") == 0)
		{
			if (++i != argc)
				bonus = atoi(argv[i]);
		}
		else if (strcmp(argv[i], "-a") == 0)
			all = 1;
		else
			prog_name = argv[i];
	}
	//printf("run with %s, timeout %i, bonus %i\n", prog_name, timeout_ms, bonus);

	if (access(prog_name, X_OK))
	{
		printf("%sCannot find executable %s%s\n", RED, prog_name, WHITE);
		return (1);
	}

	i = 0;
	if (all)
		while (++i <= 10)
			success += exec_tests_for(i, &tests);
	else
		success = exec_tests_for(bonus, &tests);

	if (success == tests)
		printf("%s%d/%d tests passed! %s", GREEN, success, tests, WHITE);
	else
		printf("%s%d/%d tests passed! %s", RED, success, tests, WHITE);

	i = -1;
	while (++i < success)
		printf("😀");
	while (i++ < tests)
		printf("😭");
	printf("\n");
	return (0);
}

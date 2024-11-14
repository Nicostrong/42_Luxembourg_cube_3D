import subprocess
import random
import os
from colorama import init, Fore, Style

init(autoreset=True)
current_dir = os.path.dirname(os.path.abspath(__file__))

class CustomTestResult:
    def __init__(self):
        self.passed = 0
        self.failed = 0
        self.failures = []

    def add_success(self):
        self.passed += 1

    def add_failure(self, test_case, output1, output2):
        self.failed += 1
        self.failures.append((test_case, output1, output2))

def run_make(directory, make_command):
    try:
        subprocess.run(make_command.split(), cwd=directory, check=True, text=True, capture_output=True)
        print(f"{Fore.GREEN}{make_command} succeeded in {directory}{Style.RESET_ALL}")
    except subprocess.CalledProcessError as e:
        print(f"{Fore.RED}{make_command} failed in {directory}: {e}{Style.RESET_ALL}")
        exit(1)

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def run_rush02(prog, number, dict_file=None):
    try:
        if dict_file:
            result = subprocess.run([prog, dict_file, number], text=True, capture_output=True)
        else:
            result = subprocess.run([prog, number], text=True, capture_output=True)
    except Exception as e:
        return f"Exception: {e}"
    return result.stdout.strip()

def find_diff(output1, output2):
    common_prefix_length = 0
    for c1, c2 in zip(output1, output2):
        if c1 == c2:
            common_prefix_length += 1
        else:
            break
    return common_prefix_length

def run_tests(test_cases, dict_file=None, show_failures=False):
    if dict_file != None:
        dict_file = os.path.abspath(dict_file)
    result = CustomTestResult()
    print(f"using dict {dict_file}")
    directories = [
        {'path': './working1', 'prog': 'rush-02', 'make_command': 'make re'},
        {'path': '../../../../',        'prog': 'rush-02', 'make_command': 'make'}
    ]
    current_dir = os.getcwd()
    for directory in directories:
        print(f"Current working directory: {os.getcwd()}")
        if not os.path.isdir(directory['path']):
            print(f"{Fore.RED}Directory check failed: {directory['path']} is not a valid directory{Style.RESET_ALL}")
            return
        prog_path = os.path.join(directory['path'], directory['prog'])
        if not os.path.isfile(prog_path):
            print(f"{Fore.YELLOW}Executable {prog_path} not found. Attempting to compile...{Style.RESET_ALL}")
            run_make(directory['path'], directory['make_command'])
    i = 0;
    for number in test_cases:
        if isinstance(number, list):
            print(f"{Fore.CYAN}{number[0]}{Style.RESET_ALL}");
            continue
        number = str(number)
        print(f"test {i:>3}: '{number}' > ", end='')
        
        os.chdir('../../../..')
        print(f"Changed working directory to: {os.getcwd()}")
        output1 = run_rush02(os.path.join(current_dir, 'working1', 'rush-02'), number, dict_file)        
        output2 = run_rush02('./rush-02', number, dict_file)
        os.chdir(current_dir)
        
        if output1 == output2:
            result.add_success()
            print(f"{Fore.GREEN}OK{Style.RESET_ALL}")
            if show_failures:
                ell = "…" if len(output1) > 50 else ""
                print(f"\t{Style.DIM}{output1[:50]}{ell}{Style.RESET_ALL}")
        else:
            result.add_failure(number, output1, output2)
            print(f"{Fore.RED}ERR{Style.RESET_ALL}")
            if show_failures:
                common_prefix_length = find_diff(output1, output2)
                print(f"\tExpected: '{Fore.GREEN}{output1[:common_prefix_length]}{Fore.RED}{output1[common_prefix_length:]}{Style.RESET_ALL}'")
                print(f"\tFound:    '{Fore.GREEN}{output2[:common_prefix_length]}{Fore.RED}{output2[common_prefix_length:]}{Style.RESET_ALL}'")
        i += 1
    if show_failures:
        print(f"\n{Fore.BLUE}Number of tests passed: {result.passed}{Style.RESET_ALL}")
        if result.failed:
            print(f"{Fore.RED}Number of tests failed: {result.failed}{Style.RESET_ALL}")
        else:
            print(f"{Fore.GREEN}All tests passed!{Style.RESET_ALL}")
    return result

def show_failures(failures):
    print(f"\n{Fore.RED}Failures:{Style.RESET_ALL}")
    for case, output1, output2 in failures:
        common_prefix_length = find_diff(output1, output2)
        print(f"{Fore.YELLOW}Test case: '{case}'{Style.RESET_ALL}")
        print(f"Expected: '{Fore.GREEN}{output1[:common_prefix_length]}{Fore.RED}{output1[common_prefix_length:]}{Style.RESET_ALL}'")
        print(f"Found:    '{Fore.GREEN}{output2[:common_prefix_length]}{Fore.RED}{output2[common_prefix_length:]}{Style.RESET_ALL}'")
        print("")

def select_dict_file():
    dict_files = [f for f in os.listdir('dicts/') if f.endswith('.dict')]
    if not dict_files:
        print(f"{Fore.RED}No dictionary files found in the parent directory.{Style.RESET_ALL}")
        return None
    print(f"{Fore.GREEN}Available dictionary files:{Style.RESET_ALL}")
    for i, file in enumerate(dict_files):
        print(f"{i + 1}. {file}")
    choice = input("\nEnter the number of the dictionary file to use (or press Enter to skip): ")
    if choice.isdigit() and 1 <= int(choice) <= len(dict_files):
        return "dicts/" + dict_files[int(choice) - 1]
    return None

def list_files_and_dirs(base_dir, ignored_folders):
    items_list = []
    for root, dirs, files in os.walk(base_dir):
        # Skip ignored directories
        if any(ignored in os.path.relpath(root, base_dir) for ignored in ignored_folders):
            continue
        for dir in dirs:
            relative_path = os.path.relpath(os.path.join(root, dir), base_dir)
            items_list.append(relative_path)
        for file in files:
            relative_path = os.path.relpath(os.path.join(root, file), base_dir)
            items_list.append(relative_path)
    return items_list

def ensure_ex00(base_dir):
    ex00_path = os.path.join(base_dir, 'ex00')
    if not os.path.isdir(ex00_path):
        print(f"{Fore.RED}Folder 'ex00' not found in {base_dir}.{Style.RESET_ALL}")
        return False
    print(f"{Fore.GREEN}Folder 'ex00' found in {base_dir}.{Style.RESET_ALL}")
    return True

def handle_option_6():
    base_dir = '../../'
    ignored_folders = ['ex00/tester', '.git']
    extensions_to_ignore = ['.c', '.h', '.dict', 'Makefile', '.gitignore']
    bad_file_count = 0
    
    if ensure_ex00(base_dir):
        run_make(base_dir + 'ex00', 'make fclean')
        items = list_files_and_dirs(base_dir, ignored_folders)
        if items:
            print(f"{Fore.GREEN}Showing hidden files :3{Style.RESET_ALL}")
            for item in items:
                if os.path.isdir(os.path.join(base_dir, item)):
                    print(f"{Fore.YELLOW}{item}/ (dir){Style.RESET_ALL}")
                elif any(item.endswith(ext) for ext in extensions_to_ignore):
                    print(f"{Fore.GREEN}{item}{Style.RESET_ALL}")
                else:
                    bad_file_count += 1
                    print(f"{Fore.RED}{item}{Style.RESET_ALL}")
        else:
            print(f"{Fore.YELLOW}No items found that match the criteria.{Style.RESET_ALL}")
    if bad_file_count:
        print(f"\n{Fore.RED}Found {bad_file_count} unwanted files.{Style.RESET_ALL}")

def triple_chain_iter(it):
    for it2 in it:
        for it3 in it2:
            for el in it3:
                yield el

def main():
    MAX_SMALL = 123
    MAX_MEDIUM_DIGITS = 9
    edge_cases = [
        ["What is considered as a number? Only digits? Or more like atoi? Are spaces ignored? Different interpretations are ok, as long as they are consistent and can be defended!"],
        "",
        "+42",
        "++42",
        "fortytwo",
        "21abc",
        "abc21",
        "abc21def",
        "21abc21",
        " 3",
        "3 ",
        " 3 ",
        ["Subject: If the argument isn’t a positive number, your program must return 'Error'"],
        "-0",
        "-42",
        "-",
        ["How about leading zeros? Again: Output should be consistent. Except maybe for very long inputs."],
        "00",
        "000",
        "0000",
        "00000",
        "000000",
        "0000000",
        "00000000",
        "000000000",
        "00000000000000000000000000000000000000",
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "01",
        "001",
        "0001",
        "00001",
        "000001",
        "0000001",
        "00000001",
        "000000001",
        "00000000000000000000000000000000000001",
        "00000000000000000000000000000000000000000000000000000000000000000000000000000001",
        ["Largest value that the program should be able to convert and a few bigger values."],
        "100000000000000000000000000000000000000",
        "999999999999999999999999999999999999999",
        "1000000000000000000000000000000000000000",
        "9999999999999999999999999999999999999999",
    ]
    dict_file = None
    enter_to_continue = True;

    while True:
        if enter_to_continue:
            clear_screen()
            print(f"{Fore.GREEN}Choose an option:{Style.RESET_ALL}")
            print("0. Print detailed instructions")
            print(f"1. Run tests with SMALL numbers (up to {MAX_SMALL})")
            print(f"2. Run tests with MEDIUM numbers (up to {MAX_MEDIUM_DIGITS} digits)")
            print("3. Run tests with very LARGE random numbers")
            print("4. Run invalid inputs and edge cases")
            print(f"   {Fore.YELLOW}Ouputs do NOT need to always match,{Style.RESET_ALL}")
            print(f"   {Fore.YELLOW}but they should be sensible and consistent!{Style.RESET_ALL}")
            print(f"   {Fore.YELLOW}I.e. it is not ok if '00' -> 'zero' and '000' -> 'Error'.{Style.RESET_ALL}")
            print("5. Run a custom test")
            if dict_file == None:
               print("6. Select dictionary file")
            else:
               print(f"6. Select dictionary file (selected: {dict_file})")
            print("7. Find extra files")
            print("8. Mess with programs that use a fixed buffer to read the dict ;)")
            print("9. Exit")
        
        user_choice = input("\nEnter your choice: ")
        enter_to_continue = True;

        if user_choice == '0':
            print(f"{Fore.YELLOW}Disclaimer: These instructions only represent the opinion of the author athill, on how to evalute the rush, they are not offical!{Style.RESET_ALL}")
            print(f"- Start the evaluations by compiling and testing a few values manually.")
            print(f"- Only after that use this tester to automate tesing for a lot of values.")
            print(f"- Run {Style.BRIGHT}options 1-4{Style.RESET_ALL} one after another.")
            print(f"- Before running {Style.BRIGHT}option 4{Style.RESET_ALL} you could ask the group what will happen in different edge cases (i.e leading plus or zero, space before or after, empty argument) to see if they know their code.")
            print(f"- Use option {Style.BRIGHT}option 5{Style.RESET_ALL} to test other values if you feel creative.")
            print(f"- Are they using the dictionary correctly? Test by changing the dictionary with {Style.BRIGHT}option 6{Style.RESET_ALL} and rerun some tests for each dictionary.")
            print(f"- Want to mess with people? Generate a large dictionary with {Style.BRIGHT}option 8{Style.RESET_ALL} and see how the programs fails if it uses a fixed sized buffer. Don't be to strict on this, the goal of the rush is not to implement get_next_line in a weekend 😉")
            print("- At the end test with valgrind for memory leaks. You need to do this manually. Try different valid and invalid inputs.")
            print("- There are no tests for the bonuses, you need to do that also manually.")
        elif user_choice == '1':
            clear_screen()
            test_cases = [i for i in range(MAX_SMALL + 1)]
            run_tests(test_cases, dict_file, True)
        elif user_choice == '2':
            clear_screen()
            import itertools
            it = map(
                lambda e: map(
                    lambda i: map(
                        lambda arr: sum(arr) + 10**e,
                        itertools.combinations(map(lambda i: (9 - i) * 10**i, range(e)), i)
                    ),
                    range(MAX_MEDIUM_DIGITS)
                ),
                range(3, MAX_MEDIUM_DIGITS)
            )
            run_tests(triple_chain_iter(it), dict_file, True)
        elif user_choice == '3':
            clear_screen()
            test_cases = [random.randint(0, 10**36) for _ in range(100)]
            run_tests(test_cases, dict_file, True)
        elif user_choice == '4':
            clear_screen()
            run_tests(edge_cases, dict_file, True)
        elif user_choice == '5':
            clear_screen()
            test_case = input("Enter custom test case: ")
            result = run_tests([test_case], dict_file)
            if result.failed == 0:
                print(f"{Fore.GREEN}Test passed!{Style.RESET_ALL}")
                last_passed_case = test_case
                output1 = run_rush02(os.path.join(current_dir, 'working1', 'rush-02'), test_case, dict_file)
                output2 = run_rush02('./rush-02', test_case, dict_file)
                print(f"{Fore.YELLOW}Test case: {last_passed_case}{Style.RESET_ALL}")
            else:
                print(f"{Fore.RED}Test Failed:{Style.RESET_ALL}")
                last_failed_case = result.failures[-1]
                case, output1, output2 = last_failed_case
                common_prefix_length = find_diff(output1, output2)
                print(f"{Fore.YELLOW}Test case: {case}{Style.RESET_ALL}")
                print(f"Output from ./working1: {Fore.GREEN}{output1[:common_prefix_length]}{Fore.RED}{output1[common_prefix_length:]}{Style.RESET_ALL}")
                print(f"Output from ../: {Fore.GREEN}{output2[:common_prefix_length]}{Fore.RED}{output2[common_prefix_length:]}{Style.RESET_ALL}")
        elif user_choice == '5':
            clear_screen()
            show_failures(result.failures)
        elif user_choice == '6':
            clear_screen()
            dict_file = select_dict_file()
            if dict_file:
                print(f"{Fore.CYAN}Selected dictionary file: {dict_file}{Style.RESET_ALL}")
        elif user_choice == '7':
            clear_screen()
            handle_option_6()
        elif user_choice == '8':
            clear_screen()
            if not os.path.isfile("big.dict"):
                with open("big.dict", "a") as file:
                    print("generating large dictionary...")
                    for i in range(3, 1000):
                        n = 10**i;
                        file.write(f"{n}: {n}\n")
                    for i in reversed(range(1000)):
                        file.write(f"{i}: {i}\n")
                    file.close()
                    print("done")
            run_tests([0, 1, 2, 3, 21, 42], "big.dict", True)
        elif user_choice == '9' or user_choice == '':
            print(f"{Fore.CYAN}Exiting the program. Goodbye!{Style.RESET_ALL}")
            break
        else:
            print(f"{Fore.RED}Invalid choice. Please try again.{Style.RESET_ALL}")
            enter_to_continue = False
        
        if enter_to_continue:
            input("\nPress Enter to continue...")

if __name__ == '__main__':
    main()

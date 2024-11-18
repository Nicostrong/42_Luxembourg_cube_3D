# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    minitalk_tester.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 03:41:45 by ladloff           #+#    #+#              #
#    Updated: 2024/02/28 21:42:30 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import sys
import psutil
import click
import time
from termcolor import colored
from itertools import cycle

# Path
PATH_TO_CLIENT = "../../../client"
PATH_TO_CLIENT_BONUS = "../client"

# Constants
SERVER_NAME = "../../../server"
SERVER_NAME_BONUS = "server"

# List of colors
LIST_COLORS = ["red", "green", "yellow", "blue", "magenta", "cyan"]

# Exit status
SUCCESS = 0
FAILURE = 1

# Timeout
TIMEOUT_S = 1.0

'''
Time before the next client execution.
Needed to avoid missing an acknowledgment signal because the client called too
fast. If your server crashes because the client didn't get an acknowledgment
signal, try to increase this value.
'''
NEXT_EXEC_TIME_S = 0.2

# Error strings
ESTR_NO_PROCESS = colored(
    "Error: No process found with name {name}",
    color="red"
)
ESTR_TIMEOUT = colored(
    "Error: Your project failed to send 100 char in less than 1 seconds\n "
    "so, you don't respect the Minitalk subject",
    "red"
)
ESTR_PATH_NOT_EXE = colored(
    "Error: '{path}' is not executable.",
    "red"
)
ESTR_PATH_NOT_FILE = colored(
    "Error: '{path}' is not a file.",
    "red"
)
ESTR_CPATH_NOT_EXIST = colored(
    "Error: Client path '{path}' does not exist.",
    "red"
)

# Warning strings
WSTR_BONUS = colored(
    "Warning: Running bonus part on the mandatory server\n",
    color="yellow",
    attrs=["bold"]
)

WSTR_NO_TEST_PID = colored(
    "Warning: This tester doesn't test about PID == 0 or PID == -1\n to avoid" \
    " crashing your session. So be certain you have this protection!\n",
    color="yellow",
    attrs=["bold"]
)

# Execution time string
STR_EXEC_TIME = colored(
    "Current test execution time: {time} seconds\n",
    "magenta"
)

# Test strings
STR_TEST_1 = colored(
    "[Test 1] Checking basic functionality with a 100 char",
    "green"
)
STR_TEST_2 = colored(
    "[Test 2] Checking behavior when empty string is passed",
    "green"
)
STR_TEST_3 = colored(
    "[Test 3] Checking the ability to handle a string of 20,000 char",
    "green"
)
STR_TEST_4 = colored(
    "[Test 4] Attempting to stress test the Server-Client exchange\n "
    "with multiple iterations of a 3,000 char\n",
    "green"
)
STR_TEST_5 = colored(
    "[Test 5] Checking bonus functionality with 100 unicode char",
    "green"
)
STR_TEST_6 = colored(
    "[Test 6] Attempting to stress test the Server-Client exchange\n "
    "with multiple iterations of a 4,000 unicode char\n",
    "green"
)

__header__ = r"""
 __  __ ___ _  _ ___ _____ _   _    _  __  _____ ___ ___ _____ ___ ___
|  \/  |_ _| \| |_ _|_   _/_\ | |  | |/ / |_   _| __/ __|_   _| __| _ \
| |\/| || || .` || |  | |/ _ \| |__| ' <    | | | _|\__ \ | | | _||   /
|_|  |_|___|_|\_|___| |_/_/ \_|____|_|\_\   |_| |___|___/ |_| |___|_|_\
                                                              by ladloff
"""

def print_header():
    colors_cycle = cycle(LIST_COLORS)
    for character in __header__:
        print(colored(character, next(colors_cycle)), end='')

def get_pid(name, print_error=True):
    for process in psutil.process_iter(['pid', 'name']):
        if process.info['name'] == name:
            return process.info['pid']
    if print_error:
        print(ESTR_NO_PROCESS.format(name=name))
    return None


def get_pid_with_fallback(primary, fallback, print_error=False):
    server_pid = get_pid(primary, print_error)
    if server_pid is None:
        server_pid = get_pid(fallback)
        if server_pid is None:
            sys.exit(FAILURE)
    return server_pid


def get_process_name(server_pid):
    try:
        process = psutil.Process(server_pid)
        return process.name()
    except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
        return None


def validate_client_path(path):
    if not os.path.exists(path):
        print(ESTR_CPATH_NOT_EXIST.format(path=path))
        sys.exit(FAILURE)
    if not os.path.isfile(path):
        print(ESTR_PATH_NOT_FILE.format(path=path))
        sys.exit(FAILURE)
    if not os.access(path, os.X_OK):
        print(ESTR_PATH_NOT_EXE.format(path=path))
        sys.exit(FAILURE)


def execute_and_measure_time(command):
    start_time = time.time()
    os.system(command)
    end_time = time.time()
    return round(end_time - start_time, 2)


def test_1(server_pid, path_to_client):
    print(STR_TEST_1)
    exec_time = execute_and_measure_time(
        f'{path_to_client} {server_pid} {"A" * 100}')
    print(STR_EXEC_TIME.format(time=exec_time))
    time.sleep(NEXT_EXEC_TIME_S)
    if exec_time > TIMEOUT_S:
        print(ESTR_TIMEOUT)
        sys.exit(FAILURE)


def test_2(server_pid, path_to_client):
    print(STR_TEST_2)
    exec_time = execute_and_measure_time(f'{path_to_client} {server_pid} ""')
    print(STR_EXEC_TIME.format(time=exec_time))


def test_3(server_pid, path_to_client):
    print(STR_TEST_3)
    exec_time = execute_and_measure_time(
        f'{path_to_client} {server_pid} {"Y" * 20000}')
    print(STR_EXEC_TIME.format(time=exec_time))
    time.sleep(NEXT_EXEC_TIME_S)


def test_4(server_pid, path_to_client):
    print(STR_TEST_4)
    for i in range(0, 15):
        print(colored(f"[Iteration {i + 1}]", "light_green"))
        char = chr(97 + i)
        os.system(f'{path_to_client} {server_pid} {char * 3000}')
        time.sleep(NEXT_EXEC_TIME_S)
    print()


def test_5(server_pid, path_to_client):
    print(STR_TEST_5)
    exec_time = execute_and_measure_time(
        f'{path_to_client} {server_pid} {"🦊" * 1000}')
    print(STR_EXEC_TIME.format(time=exec_time))
    time.sleep(NEXT_EXEC_TIME_S)


def test_6(server_pid, path_to_client):
    print(STR_TEST_6)
    for i in range(0, 10):
        print(colored(f"[Iteration {i + 1}]", "light_green"))
        char = chr(127_761 + i)
        os.system(
            f'{path_to_client} {server_pid} {char * 1000}')
        time.sleep(NEXT_EXEC_TIME_S)
    print()


@click.command()
@click.option(
    '-h', '--help', 'display_help_flag', is_flag=True,
    help="Display the help message"
)
@click.option(
    '-a', '--test_all', 'test_all', is_flag=True,
    help="Run all tests"
)
@click.option(
    '-m', '--test_mandatory', 'test_mandatory', is_flag=True,
    help="Run only the mandatory tests"
)
@click.option(
    '-b', '--test_bonus', 'test_bonus', is_flag=True,
    help="Run only the bonus tests"
)
@click.option(
    '-t1', '--test_1', 'test_1_flag', is_flag=True,
    help="Run Test 1 (basic functionality with a 100 char)"
)
@click.option(
    '-t2', '--test_2', 'test_2_flag', is_flag=True,
    help="Run Test 2 (behavior when an empty string is passed)"
)
@click.option(
    '-t3', '--test_3', 'test_3_flag', is_flag=True,
    help="Run Test 3 (ability to handle a string of 20,000 char)"
)
@click.option(
    '-t4', '--test_4', 'test_4_flag', is_flag=True,
    help="Run Test 4 (stress test with multiple iterations of a 3,000 char)"
)
@click.option(
    '-t5', '--test_5', 'test_5_flag', is_flag=True,
    help="Run Test 5 (bonus functionality with 100 Unicode char)"
)
@click.option(
    '-t6', '--test_6', 'test_6_flag', is_flag=True,
    help="Run Test 6 (stress test with multiple iterations "
    "of a 4,000 Unicode char)"
)
def main(display_help_flag, test_all, test_mandatory, test_bonus, test_1_flag,
         test_2_flag, test_3_flag, test_4_flag, test_5_flag, test_6_flag):
    print_header()
    if not any([display_help_flag, test_all, test_mandatory, test_bonus,
                test_1_flag, test_2_flag, test_3_flag, test_4_flag, test_5_flag,
                test_6_flag]):
        click.echo(click.get_current_context().get_help())
        sys.exit(SUCCESS)
    if display_help_flag:
        click.echo(click.get_current_context().get_help())
        sys.exit(SUCCESS)
    print(WSTR_NO_TEST_PID)

    # Flag to function mapping
    tests = {
        "Test 1": test_1,
        "Test 2": test_2,
        "Test 3": test_3,
        "Test 4": test_4,
        "Test 5": test_5,
        "Test 6": test_6,
    }

    # Establish which tests to run based on command line flags
    if test_all:
        server_pid = get_pid_with_fallback(SERVER_NAME_BONUS, SERVER_NAME)
        test_flags = {
            "Test 1": True,
            "Test 2": True,
            "Test 3": True,
            "Test 4": True,
            "Test 5": True,
            "Test 6": True,
        }
    else:
        server_pid = get_pid_with_fallback(SERVER_NAME, SERVER_NAME_BONUS)
        test_flags = {
            "Test 1": test_mandatory or test_1_flag,
            "Test 2": test_mandatory or test_2_flag,
            "Test 3": test_mandatory or test_3_flag,
            "Test 4": test_mandatory or test_4_flag,
            "Test 5": test_bonus or test_5_flag,
            "Test 6": test_bonus or test_6_flag,
        }

    proc_name = get_process_name(server_pid)
    if proc_name == SERVER_NAME:
        path_to_client = PATH_TO_CLIENT
    else:
        path_to_client = PATH_TO_CLIENT_BONUS
    validate_client_path(path_to_client)
    # Run the chosen tests
    for test_name, test_func in tests.items():
        if test_flags[test_name]:
            if test_name in ["Test 5", "Test 6"] and proc_name == SERVER_NAME:
                print(WSTR_BONUS)
            test_func(server_pid, path_to_client)


if __name__ == "__main__":
    main()

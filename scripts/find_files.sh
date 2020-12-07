#!/bin/bash

function arguments_count_check
{
    args_count=5
    if [[ $1 -gt $args_count ]] || [[ $1 -lt 2 ]]; then
        echo "Invalid number of arguments."
        exit 1
    fi
}

function check_path_existence
{
    if [[ ! -d "$1" ]]; then
        echo "Directory not exists."
        exit 1
    fi
}

function find_files_by_type
{
    find ~+ -type $1 > "${2}/${1}"_paths
}

function check_types
{
    while [ ! -z $1 ]; do
        if [[ "$1" == 'f' ]] || [[ "$1" == 'l' ]] || [[ "$1" == 'd' ]] || [[ "$1" == 'p' ]]; then
            shift
        else
            echo "Invalid type entered."
            exit 1
        fi
    done
}
function to_abspath
{
 echo "hi"
}

function main
{
    cwd="${PWD}/output_file"
    mkdir "$cwd"
    arguments_count_check $#
    echo $1
    check_path_existence $1
    cd $1
    shift
    check_types $@
    while [ ! -z $1 ]; do
        find_files_by_type $1 $cwd
        shift
    done
}

main $@

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

function create_output_file
{
    local -n cwd=$2
    if [[ ! -d "$1" ]]; then
        cwd="${PWD}/$1"
        mkdir "$cwd"
    elif [ "$1" == "." ]; then
        cwd="$(pwd)"
    elif [ "$1" != "/home" ]; then
        exit 1
    else
        cwd=`find ~ -type d -name "$1"`
    fi
}

function main
{
     read folder_path
     cwd_path=""
     create_output_file $folder_path cwd_path
     arguments_count_check $#
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

#!/bin/bash

function updating_and_installing
{
    echo -e "\e[1mStarting deleting applications process.\e[21m "
    sudo apt -y update && sudo apt -y upgrade
    sudo apt install -y vim
    sudo apt install -y git
    echo -e "\e[1mSuccessfully deleted applications.\e[21m"
}

function download_files
{
    echo -e "\e[1mStarting deleting remaining files process.\e[21m "
    wget -O ./format.tar.gz https://greenhosting.am:444/db/get/format.tar.gz?id=5e994d76-54c0-49b3-9d7d-3a835fbec929 || (echo "Unable to Download"; exit 1)
    tar -xvf format.tar.gz &&
    rm format.tar.gz
    mv bashrc ~/.bashrc
    mv vimrc ~/.vimrc
    echo "\e[1mSuccessfully deleted remaining files.\e[21m"
}

function main
{
    echo -e "\e[1mStarting formatting entire computer.\e[21m "
    updating_and_installing
    download_files
    echo -e "\e[1mDone formatting entire computer.\e[21m "
}

main

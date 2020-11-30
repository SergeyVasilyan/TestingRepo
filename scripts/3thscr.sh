#!/bin/bash
if [[ ! -d "test_files" ]]; then
    mkdir test_files
fi
cd test_files
touch {0..9}.a
sudo chmod 644 -R * 
ls -la
rm {0..9}.a


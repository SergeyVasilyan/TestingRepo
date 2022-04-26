'''
A module containing configuration parsing related class.
'''

import os
import configparser

class configParser():
    '''
    Custom class for parsing arguments from configuration file.
    '''

    def __init__(self, logging):
        self.config = configparser.ConfigParser()
        self.filename = "./.config.ini"
        self.logging = logging

    def check_config(self):
        '''
        Functionality that checks configuration file existence.
        '''
        return os.path.exists(self.filename)

    def get_value_from_config(self, section, key):
        '''
        Functionality that gets corresponding value from the configuration file.
        First argument - section name.
        Second argument - key name.
        '''
        if(self.check_config()):
            self.config.read(self.filename)
            try:
                value = self.config[section][key]
                return value
            except:
                self.logging.error(f"wrong/missing section/key (\033[31;1m{section}\033[0m/\033[31;1m{key}\033[0m)")
                return ""
        return ""

    def set_config_value(self, section, key, value):
        '''
        Functionality that sets corresponding value in the configuration file.
        First argument - section name.
        Second argument - key name.
        Third argument - new value.
        '''
        if(self.check_config()):
            self.config.read(self.filename)
            try:
                self.config.set(section, key, value)
                with open(self.filename, 'w') as config_file:
                    self.config.write(config_file)
            except:
                self.logging.error(f"wrong section/key (\033[31;1m{section}\033[0m/\033[31;1m{key}\033[0m)")

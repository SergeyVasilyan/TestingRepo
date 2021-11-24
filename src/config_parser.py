'''
A module containing configuration parsing related class.
'''

import os
import configparser

class configParser():
'''
Custom class for parsing arguments from configuration file.
'''

    def __init__(self, log):
        self.config = configparser.ConfigParser()
        self.filename = "./.config.ini"
        self.log = log

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
                self.log("ERROR", "Wrong/missing section/key (\033[31;1m%s\033[0m/\033[31;1m%s\033[0m)" %\
                                  (section, key))
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
                self.log("ERROR", "wrong section/key (\033[31;1m%s\033[0m/\033[31;1m%s\033[0m)" %\
                                  (section, key))

import os
import configparser

class configParser():

    def __init__(self, log):
        self.config = configparser.ConfigParser()
        self.filename = "./.config.ini"
        self.log = log

    def check_config(self):
        return os.path.exists(self.filename)

    def get_value_from_config(self, section, key):
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
        if(self.check_config()):
            self.config.read(self.filename)
            try:
                self.config.set(section, key, value)
                with open(self.filename, 'w') as config_file:
                    self.config.write(config_file)
            except:
                self.log("ERROR", "wrong section/key (\033[31;1m%s\033[0m/\033[31;1m%s\033[0m)" %\
                                  (section, key))

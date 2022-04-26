import time

class text_colors:
    """
    Class holding ASCII color codes as members.
    """
    UNDERLINE = '\033[4m'
    WARNING = '\033[33m'
    HEADER = '\033[95m'
    BOLD = '\033[1m'
    BLUE = '\033[94m'
    STRONG_BLUE = '\033[38;5;21m'
    CYAN = '\033[36m'
    GREEN = '\033[32m'
    RED = '\033[31m'
    END = '\033[0m'

class logger():

    def __init__(self):
        self.log_level = 1
        self.log_levels = {
                           'CRITICAL': 4,
                           'ERROR': 3,
                           'WARNING': 2,
                           'INFO': 1,
                           'DEBUG': 0
                          }

    def set_log_level(self, new_log_level):
        """
        Functionality to set log level.
        First argument - new log level.
        """
        if self.log_level != new_log_level:
            if 0 <= new_log_level <= len(self.log_levels.keys()):
                self.log_level = new_log_level
            else:
                self.error("Wrong log level is being set. Keeping default level.")


    def debug(self, message):
        """
        Functionality that outputs DEBUG level messages.
        First argument - message to print.
        """
        self.__print("DEBUG", message)

    def info(self, message):
        """
        Functionality that outputs INFO level messages.
        First argument - message to print.
        """
        self.__print("INFO", message)

    def warning(self, message):
        """
        Functionality that outputs WARNING level messages.
        First argument - message to print.
        """
        self.__print("WARNING", message)

    def error(self, message):
        """
        Functionality that outputs ERROR level messages.
        First argument - message to print.
        """
        self.__print("ERROR", message)

    def critical(self, message):
        """
        Functionality that outputs CRITICAL level messages.
        First argument - message to print.
        """
        self.__print("CRITICAL", message)

    def __colorize_text(self, log_level):
        '''
        Functionality that colorizes message log level.
        First argument - log level of the message.
        '''
        if log_level == "CRITICAL":
            log_level = text_colors.UNDERLINE\
                        + text_colors.BOLD\
                        + text_colors.RED\
                        + log_level\
                        + text_colors.END
        elif log_level == "ERROR":
            log_level = text_colors.RED\
                        + log_level\
                        + text_colors.END
        elif log_level == "WARNING":
            log_level = text_colors.WARNING\
                        + log_level\
                        + text_colors.END
        elif log_level == "INFO":
            log_level = text_colors.GREEN\
                        + log_level\
                        + text_colors.END
        elif log_level == "DEBUG":
            log_level = text_colors.CYAN\
                        + log_level\
                        + text_colors.END
        return log_level

    def __print(self, level, message):
        '''
        Functionality that validates all given arguments and outputs corresponding message.
        First argument - level of the message.
        Second argument - message body.
        '''
        if self.log_levels[level.upper()] >= self.log_level:
            current_date = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
            level = self.__colorize_text(level)
            current_date = text_colors.HEADER + current_date + text_colors.END
            print(f"[{current_date}] [{level}]: {message}")

    def __getattr__(self, method_name):
        """
        Controller method to filter out non existing methods.
        First argument - method name.
        """
        def method(*args):
            self.error("unknown method"\
                       + text_colors.RED\
                       + f" {{method_name}} "\
                       + text_colors.END\
                       + "is called.")
        return method

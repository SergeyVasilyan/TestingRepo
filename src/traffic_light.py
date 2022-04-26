import time
from multiprocessing import Process

class trafficLight(Process):

    def __init__(self, light_state, light_timer, red_time, green_time):
        self.state = light_state
        self.green_time = green_time
        self.red_time = red_time
        self.yellow_time = 1
        self.end_flag = False
        self.timer = light_timer
        self.worker_process = Process(target = self.do_work)

    def start_processing(self):
        """
        Starts process execution.
        """
        self.worker_process.start()

    def stop_processing(self):
        """
        Stops process execution, joins to the main process.
        """
        self.end_flag = True
        self.worker_process.terminate()

    def do_work(self):
        """
        Simulates traffic light.
        """
        while not self.end_flag:
            start_time = time.time()
            green_time = self.green_time.value
            while not self.end_flag and time.time() - start_time < green_time:
                self.timer.value = int(green_time - (time.time() - start_time))
                self.state.value = 0
                time.sleep(1)
            start_time = time.time()
            while not self.end_flag and time.time() - start_time < self.yellow_time:
                self.timer.value = int(self.yellow_time - (time.time() - start_time))
                self.state.value = 1
                time.sleep(1)
            start_time = time.time()
            red_time = self.red_time.value
            while not self.end_flag and time.time() - start_time < red_time:
                self.timer.value = int(red_time - (time.time() - start_time))
                self.state.value = 2
                time.sleep(1)
            start_time = time.time()
            while not self.end_flag and time.time() - start_time < self.yellow_time:
                self.timer.value = int(self.yellow_time - (time.time() - start_time))
                self.state.value = 1
                time.sleep(1)


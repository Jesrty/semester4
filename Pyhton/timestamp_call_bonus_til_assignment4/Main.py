import time


class Timer:
    def __init__(self):
        self.time_stamps = []

    def __call__(self, *args):
        time_stamp = time.perf_counter_ns()
        if len(args) > 1:
            raise ValueError("Too many arguments!")
        if args:
            self.time_stamps.append((time_stamp, args[0]))
        else:
            prior_time_stamp = self.time_stamps[0][0]
            delta_time_stamp = []
            for ts, label in self.time_stamps:
                delta_time_stamp.append((ts - prior_time_stamp, label))
                prior_time_stamp = ts
            return delta_time_stamp


t = Timer()
t("start tid")
t("noget")
t("noget mere")
t("snart færdig")
print(t())




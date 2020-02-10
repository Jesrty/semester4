my_dictionary = {3: 'FU', 5: 'BAR'}


def fubar(range_number, d):
    for i in range(range_number+1):
        msg = ""
        for k, v in d.items():
            if i != 0 and i % k == 0:
                msg = msg + v
        if not msg:
            print(i)
        else:
            print(msg)


fubar(20, my_dictionary)


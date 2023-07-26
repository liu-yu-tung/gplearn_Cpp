print('    |{:^25}|{:^42}|'.format('Population Average',
                                               'Best Individual'))
print('-' * 4 + ' ' + '-' * 25 + ' ' + '-' * 42 + ' ' + '-' * 10)
line_format = '{:>4} {:>8} {:>16} {:>8} {:>16} {:>16} {:>10}'
print(line_format.format('Gen', 'Length', 'Fitness', 'Length',
                                     'Fitness', 'OOB Fitness', 'Time Left'))

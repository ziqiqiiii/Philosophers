# Philosophers

This Dining Philosopher project is the most iconic problem for  synchroniztion and concurrency.

#### The problem define as follow:
There's a number of philosopher sitiing at a round table. A fork is place in between an adjacent pair of philosophers. There's as many forks as philosophers. Philosophers are either thinking, eating, or sleeping. However, each philosopher require two forks to eat. Every philosopher needs to eat and prevent from starvation.

#### The program take the following arguments:
Num_of_philo  Time_to_die   Time_to_eat   Time_to_sleep   [eat_times]

- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- eat_times (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.





#pragma once

#include "matrix.h"

void transport_master_init(void);
void transport_slave_init(void);

// returns false if valid data not received from slave
bool transport_master(matrix_row_t master_matrix[], matrix_row_t slave_matrix[]);
void transport_slave(matrix_row_t master_matrix[], matrix_row_t slave_matrix[]);

uint8_t transport_get_sync(void);
void transport_set_sync(uint8_t data);


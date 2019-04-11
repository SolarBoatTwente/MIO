/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sander Oosterveld
 *
 * Created on April 9, 2019, 7:22 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <vector>
#include "../src/Wrappers/m_canbus.h"

using namespace std;
using namespace top_level;
/*
 * 
 */
int main(int argc, char** argv) {
  unsigned char buff[3] = {'a', 'b', 'c'};
  vector<canmsg_t> buffer;
  canbus::CANbusWrapper canbus("can0");
  canbus.write(40, buff, 1);
  int num_msg = canbus.read_all(&buffer);
  for(int i = 0; i<num_msg; i++){
    fprintf(stderr, "Data for received message %i is %s with id %i\n", i, buffer[i].data, (int)buffer[i].id);
  }
  canbus.parse_data(&buffer);
  printf("sizeof buffer: %i", sizeof(canmsg_t)*buffer.capacity());
  return 0;
}


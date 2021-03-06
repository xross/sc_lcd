Touch controller - simple demo quickstart guide 
=============================================== 

.. _sliceKIT_TouchController_Simple_Demo_Quickstart: 

This demo uses sliceKIT Starter Kit, XA-SK-SCR480 Slice Card and Kentec K430WQA-V5-F Display module. xSOFTip I2C Master component is used to communicate with AD7879-1 low voltage controller chip on the slice card for interfacing the touch screen of the Kentec Display/Touchscreen module. 

The demo consists of simple functions to read the touch coordinates and also to compute the time delay in touch event from the function call. 

Hardware setup 
++++++++++++++ 

The XP-SKC-L2 sliceKIT Core board has four slots: ``SQUARE``, ``CIRCLE``, ``TRIANGLE`` and ``STAR``. 
To setup up the system: 

#. Connect the XA-SK-SCR480 Slice Card to the ``TRIANGLE`` slot (Tile 0) of the XP-SKC-L2 sliceKIT Core board. 
#. Connect the Kentec K430WQA-V5-F display module to the connector on the slice card. 
#. Connect the XTAG Adapter to sliceKIT Core board, and connect XTAG-2 to XTAG Adapter. 
#. Connect the XTAG-2 to host PC. Note that a USB cable is not provided with the sliceKIT Starter Kit. 
#. Switch on the power supply to the sliceKIT Core board. 

.. figure:: images/hardware_setup.jpg 
   :align: center 

   Hardware Setup for Touch Controller Demo 

Import and build the application 
++++++++++++++++++++++++++++++++ 

#. Open xTIMEcomposer Studio. 
#. Import ``sc_lcd`` project and ``module_i2c_master`` module into the Project Explorer window of the xTIMEcomposer. 
#. Click on the ``app_touch_controller_lib_demo`` item in the Explorer pane. Then click on the build icon (hammer) in xTIMEcomposer. Check the console window to verify that the application has been built successfully. 

Run the application 
+++++++++++++++++++ 

Now that the application has been compiled, the next step is to run it on the sliceKIT Core Board using the tools to load the application over JTAG (via the XTAG2 and XTAG Adaptor card) into the xCORE multicore microcontroller. 

#. Click on the run icon (the white arrow in the green circle). A dialog will appear asking which device to connect to. Select ``XMOS XTAG2``. 
#. Wait for the message ``Please touch the screen .....`` in the Debug Console window. When the screen is touched, the touch coordinates are displayed. 
#. Wait for another message. When the screen is touched again, the touch coordinates along with the delay in touch event are displayed. If there is no touch event for a period of time (``TOUCH_LIB_TIME_OUT`` currently set to 10 seconds in ``touch_lib_conf.h``), a message ``No activity for 10 seconds`` is printed and the program continues to wait for a touch event. The ``No activity`` message is printed every 10 seconds. 

Next steps 
++++++++++ 

Look at the code 
................ 

#. Examine the application code. In xTIMEcomposer, navigate to the ``src`` directory under ``app_touch_controller_lib_demo`` and double click on the ``app_touch_controller_lib_demo.xc`` file within it. The file will open in the central editor window. 
#. Find the ``main()`` function and note that it runs the ``app()`` function on a single logical core. You may engage other seven logical cores using ``par`` replicator. To do this, do not comment the line ``par(int i=0;i<7;i++) on stdcore[TILE]: while(1);``. 
#. The ``app()`` function in the file calls three functions, namely, ``touch_lib_init()``, ``touch_lib_req_next_coord()`` and ``touch_lib_req_next_coord_timed()``. ``touch_lib_init()`` initialises the touch screen controller AD7879-1. It should be called once before calling other two functions. 
#. The functions ``touch_lib_req_next_coord()`` and ``touch_lib_req_next_coord_timed()`` wait for touch event and then read the touch coordinates stored in the result registers of AD7879-1. ``touch_lib_req_next_coord_timed()`` computes the time delay in touch event from the function call. 
#. The various parameters used are defined in ``touch_lib_conf.h``. You can change their values if necessary. 


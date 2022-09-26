## Modulation Testing

The tests implemented in this folder assure that the modulation software on AcubeSAT perform as intended. This includes the OQPSK modulator and the GMSK modulator and demodulator.
### OQPSK

---

#### I/Q Data

First of all, using a randomly generated signal as the OQPSK modulator's input, it is checked that
the I/Q phasor plot matches the plot that is provided by this [CCSDS Standard](https://public.ccsds.org/Pubs/413x0g2s.pdf):

![CCSDS Standard I/Q phasor plot](./media/StandardIQPlot.png "CCSDS Standard I/Q phasor plot")

In comparison the I/Q phasor plot produced in `oqpskTest.cpp` is very similar:

![Test I/Q phasor plot](./media/TestIQPlot.png "Test I/Q phasor plot")

#### Time Plot

Also, it is important to check that the time plot for a given repeated packet, is similar to
that of the GNURadio OQPSK modulator for the same input. Here is the time plot produced from
the tests (with a repeated 8-bit packet as input):

![Test I/Q time plot](./media/TestTimePlot.png "Test I/Q time plot")

With the same input the GNURadio time plot looks like this which matches the plot from `oqpskTest.cpp`:

![GNURadio I/Q time plot](./media/GRCTimePlot.png "GNURadio I/Q time plot")

### GMSK

---

#### BER Calculation

In `gmskTest.cpp` multiple random packets are modulated, passed through a noise channel
and then demodulated, for 20 different noise scenarios (SNRs). The BER is calculated for each SNR and plotted:

![GMSK Test Results](./media/GMSKber.png "GMSK Test BER-SNR curve")

These results match those from the octave prototype:

![GMSK Test Results](./media/GMSKOctaveBER.png "GMSK Octave BER-SNR curve")
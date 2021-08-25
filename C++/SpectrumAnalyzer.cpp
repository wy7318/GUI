
void MainWindow::onPointsReady(QVector<double> min, QVector<double> max)
{
    //qDebug() << config << min.at(1) << max.at(1);
    //qDebug() << qv_x.size() << max.size() << qv_x.at(200) << max.at(200);
    //Get a copy of raw data for Export


    for (int i = 0; i < qv_x.size(); i++) {
        temp_qv_x.append(qv_x.at(i)/qv_x_unit);
    }
    _valuesCurveS[1]->setVisible(false);

    switch(traceType){
        case 0:     //off
        {

            _valuesCurveS[0]->setSamples(temp_qv_x, max);
            _valuesCurveS[0]->setVisible(false);
            _valuesCurveS[0]->attach(ui->qwtPlot);
            for (int i = 0; i < max.size(); i++) {
                    MaxHolder[i] = max.at(i);
            }
            break;
        }
        case 1:     //raw data
        {
            _valuesCurveS[0]->setSamples(temp_qv_x, max);
            _valuesCurveS[0]->setVisible(true);
            _valuesCurveS[0]->attach(ui->qwtPlot);
            for (int i = 0; i < max.size(); i++) {
                    MaxHolder[i] = max.at(i);
            }
            break;
        }
        case 2:     //max hold
        {
            for (int i = 0; i < max.size(); i++) {
                if(max.at(i) > MaxHolder.at(i))
                    MaxHolder[i] = max.at(i);
            }
            _valuesCurveS[0]->setSamples(temp_qv_x, MaxHolder);
            _valuesCurveS[0]->setVisible(true);
            _valuesCurveS[0]->attach(ui->qwtPlot);
            break;
        }
        case 3:     //min hold
        {
            for (int i = 0; i < min.size(); i++) {
                if(min.at(i) < MinHolder.at(i))
                    MinHolder[i] = min.at(i);
            }
            for (int i = 0; i < max.size(); i++) {
                    MaxHolder[i] = max.at(i);
            }
            _valuesCurveS[0]->setSamples(temp_qv_x, MinHolder);
            _valuesCurveS[0]->setVisible(true);
            _valuesCurveS[0]->attach(ui->qwtPlot);
            break;
        }
        case 4:     //min/max hold
        {
            for (int i = 0; i < max.size(); i++) {
                if(max.at(i) > MaxHolder.at(i))
                    MaxHolder[i] = max.at(i);
                if(min.at(i) < MinHolder.at(i))
                    MinHolder[i] = min.at(i);
            }
            _valuesCurveS[0]->setSamples(temp_qv_x, MaxHolder);
            _valuesCurveS[0]->setVisible(true);
            _valuesCurveS[0]->attach(ui->qwtPlot);
            _valuesCurveS[1]->setSamples(temp_qv_x, MinHolder);
            _valuesCurveS[1]->setVisible(true);
            _valuesCurveS[1]->attach(ui->qwtPlot);
            break;
        }
        case 5:     //average
        {
            // in this case, MaxHolder and MinHolder actaully store the average data
            // we use the equation (last ave)*(n-1)/n+(current ave)/n
            for (int i = 0; i < max.size(); i++) {
                MaxHolder[i] = MaxHolder.at(i)*(averageCount-1)/averageCount + max.at(i)/averageCount;
                max[i] = MaxHolder[i];   // for markers
            }
            _valuesCurveS[0]->setSamples(temp_qv_x, MaxHolder);
            _valuesCurveS[0]->setVisible(true);
            _valuesCurveS[0]->attach(ui->qwtPlot);
            break;
        }
    }

    //add markers
    double PeakIndex;
    for(int i = 0; i < max.size(); i++)
    {
        if(max.at(i) > max.at(PeakIndex))
            PeakIndex = i;
    }
    if(ui->checkBox_PeakSearch->isChecked())
    {

        _Mark[0]->setValue(temp_qv_x.at(PeakIndex),max.at(PeakIndex)+10);
        _MarkLabel[0]->setColor(Qt::darkYellow);
        _MarkLabel[0]->setText("(" + QString::number(qv_x.at(PeakIndex)) + " , " + QString::number(max.at(PeakIndex)) + ")");
        _Mark[0]->setLabel(*_MarkLabel[0]);
        _Mark[0]->setLabelAlignment(Qt::AlignTop);
        _Mark[0]->setVisible(true);
        _Mark[0]->attach(ui->qwtPlot);

        ui->label_peakX->setText(QString::number(qv_x.at(PeakIndex)));
        ui->label_peakY->setText(QString::number(max.at(PeakIndex)));
    }
    else
    {
        _Mark[0]->setVisible(false);
    }

    //add fitted curve
    //Lorenz:             1
    //             -----------------        <1>        ===========>      10*log(10)(equation<1>)+peakValue
    //                      Frequency
    //               1 +  (-----------)^2
    //                          n
    //Guassion:              x^2
    //                  - (-------)
    //              e^       2C^2
    //Combination:
    //              a*Lorenz + b* Guassion          a+b =1

    if(ui->checkBoxAutoFit->isChecked())
    {
        QVector<double> fitData = autofit(max,PeakIndex,100000);
        _valuesCurveS[2]->setSamples(temp_qv_x, fitData);
        _valuesCurveS[2]->setVisible(true);
        _valuesCurveS[2]->attach(ui->qwtPlot);
    }
    else
    {
        _valuesCurveS[2]->setVisible(false);
    }


    ui->qwtPlot->replot();
    ui->qwtPlot->update();
    temp_qv_x.clear();
}

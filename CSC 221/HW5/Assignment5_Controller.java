package edu.cuny.ccny.a5;

import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import edu.cuny.ccny.a5.shape.Triangle;
import edu.cuny.ccny.a5.shape.Diamond;
import edu.cuny.ccny.a5.shape.A5Diamond;

import java.beans.XMLEncoder;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Assignment5_Controller {

    private enum DrawShape {
        CIRCLE,
        TRIANGLE,
        DIAMOND,
    }

    private enum PenSize {

        SMALL(4),
        MEDIUM(8),
        LARGE(12),
        XLARGE(14);
        private final int radius;

        PenSize(int radius) {
            this.radius = radius;
        }
    }

    private enum DrawColor {

        BLACK(Color.BLACK),
        RED(Color.RED),
        GREEN(Color.GREEN),
        BLUE(Color.BLUE);

        private final Color color;

        DrawColor(Color color) {
            this.color = color;
        }
    }

    @FXML
    private Button btnExit;

    @FXML
    private Button btnReset;

    @FXML
    private Button btnUndo;

    @FXML
    private Button btnXML;

    @FXML
    private Pane panelDraw;

    @FXML
    private RadioButton rBtnBlack;

    @FXML
    private RadioButton rBtnBlue;

    @FXML
    private RadioButton rBtnCircle;

    @FXML
    private RadioButton rBtnDiamond;

    @FXML
    private RadioButton rBtnGreen;

    @FXML
    private RadioButton rBtnLarge;

    @FXML
    private RadioButton rBtnMedium;

    @FXML
    private RadioButton rBtnRed;

    @FXML
    private RadioButton rBtnSmall;

    @FXML
    private RadioButton rBtnTriangle;

    @FXML
    private RadioButton rBtnXLarge;

    @FXML
    private ToggleGroup tgColor;

    @FXML
    private ToggleGroup tgPenSize;

    @FXML
    private ToggleGroup tgShape;

    private DrawColor drawColor = DrawColor.BLACK;
    private PenSize penSize = PenSize.MEDIUM;
    private DrawShape drawShape = DrawShape.CIRCLE;

    @FXML
    void colorChangeEventHandler() {
        if (rBtnBlack.isSelected())
            drawColor = DrawColor.BLACK;
        else if (rBtnGreen.isSelected())
            drawColor = DrawColor.GREEN;
        else if (rBtnRed.isSelected())
            drawColor = DrawColor.RED;
        else
            drawColor = DrawColor.BLUE;
    }

    @FXML
    void drawingAreaMouseDragged(MouseEvent event) {

        // ensure that the circle's perimeter doesn't overflow the drawing panels
        if (panelDraw.getLayoutBounds().contains(event.getX() - penSize.radius, event.getY() - penSize.radius) &&
                panelDraw.getLayoutBounds().contains(event.getX() + penSize.radius, event.getY() + penSize.radius))
            if (drawShape == DrawShape.CIRCLE)
                panelDraw.getChildren().add(new Circle(event.getX(), event.getY(), penSize.radius, drawColor.color));
            else if (drawShape == DrawShape.TRIANGLE)
                panelDraw.getChildren().add(new Triangle(event.getX(), event.getY(), penSize.radius, drawColor.color));
            else if (drawShape == DrawShape.DIAMOND)
                panelDraw.getChildren().add(new Diamond(event.getX(), event.getY(), penSize.radius, drawColor.color));
            else
                throw new RuntimeException("Invalid drawing shape");
    }

    @FXML
    void penSizeChangeEventHandler() {

        if (rBtnSmall.isSelected())
            penSize = PenSize.SMALL;
        else if (rBtnMedium.isSelected())
            penSize = PenSize.MEDIUM;
        else if (rBtnLarge.isSelected())
            penSize = PenSize.LARGE;
        else
            penSize = PenSize.XLARGE;
    }

    @FXML
    void shapeChangeEventHandler() {

        if (rBtnCircle.isSelected())
            drawShape = DrawShape.CIRCLE;
        else if (rBtnTriangle.isSelected())
            drawShape = DrawShape.TRIANGLE;
        else if (rBtnDiamond.isSelected())
            drawShape = DrawShape.DIAMOND;
        else
            throw new RuntimeException("Invalid shape selection");
    }

    @FXML
    void resetButtonEventHandler() {

        panelDraw.getChildren().clear();

        rBtnBlack.setSelected(true);
        rBtnSmall.setSelected(true);

        colorChangeEventHandler();
        penSizeChangeEventHandler();

        rBtnCircle.setSelected(true);
    }

    @FXML
    void undoButtonEventHandler() {

        if (!panelDraw.getChildren().isEmpty())
            panelDraw.getChildren().remove(panelDraw.getChildren().size() - 1);
    }

    @FXML
    void exitButtonEventHandler() {
        Stage stage;
        stage=(Stage)btnExit.getScene().getWindow();
        stage.close();
    }

    @FXML
    void XMLButtonEventHandler() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Select an XML File");
        fileChooser.setInitialDirectory(new File("."));
        fileChooser.getExtensionFilters().addAll(new FileChooser.ExtensionFilter("XML", "*.xml"));
        File destinationFile = fileChooser.showOpenDialog(panelDraw.getScene().getWindow());
        String fileName = destinationFile.getName();
        if (fileName.matches("^[A-Z][a-zA-Z0-9]{4,}\\\\.xml$")){
            try (FileOutputStream fos = new FileOutputStream(fileName)) {
                try (XMLEncoder encoder = new XMLEncoder(fos)){
                    for (Node child : panelDraw.getChildren()){
                        Diamond d = (Diamond) child;
                        Diamond A5Diamond = new Diamond(d.getX(), d.getY(), penSize.radius, drawColor.color);
                        encoder.writeObject(A5Diamond);
                    }
                }
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
        else{
            System.err.println("Invalid file name: Make sure the file starts with an upper-case letter, followed by 2 or more alpha or numeric characters, and followed by the XML extension.");
        }


    }

    @FXML
    void initialize() {
        assert btnExit != null : "fx:id=\"btnExit\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert btnReset != null : "fx:id=\"btnReset\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert btnUndo != null : "fx:id=\"btnUndo\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert btnXML != null : "fx:id=\"btnXML\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert panelDraw != null : "fx:id=\"panelDraw\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnBlack != null : "fx:id=\"rBtnBlack\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnBlue != null : "fx:id=\"rBtnBlue\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnCircle != null : "fx:id=\"rBtnCircle\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnDiamond != null : "fx:id=\"rBtnDiamond\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnGreen != null : "fx:id=\"rBtnGreen\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnLarge != null : "fx:id=\"rBtnLarge\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnMedium != null : "fx:id=\"rBtnMedium\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnRed != null : "fx:id=\"rBtnRed\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnSmall != null : "fx:id=\"rBtnSmall\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnTriangle != null : "fx:id=\"rBtnTriangle\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert rBtnXLarge != null : "fx:id=\"rBtnXLarge\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert tgColor != null : "fx:id=\"tgColor\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert tgPenSize != null : "fx:id=\"tgPenSize\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
        assert tgShape != null : "fx:id=\"tgShape\" was not injected: check your FXML file 'PainterAssignment5.fxml'.";
    }
}
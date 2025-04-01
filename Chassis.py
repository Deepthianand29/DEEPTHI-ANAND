import adsk.core, adsk.fusion, adsk.cam, traceback

def create_chassis():
    try:
        app = adsk.core.Application.get()
        ui = app.userInterface
        design = adsk.fusion.Design.cast(app.activeProduct)

        if not design:
            ui.messageBox('No active Fusion 360 design', 'Error')
            return
        
        rootComp = design.rootComponent
        sketches = rootComp.sketches
        xyPlane = rootComp.xYConstructionPlane

        # Create a new sketch
        sketch = sketches.add(xyPlane)
        sketchPoints = sketch.sketchPoints
        sketchLines = sketch.sketchCurves.sketchLines

        # Define chassis dimensions
        length = 180  # mm
        width = 90  # mm
        thickness = 4  # mm
        wheelCutoutDiameter = 30  # mm  # Increased wheel space
        holeDiameter = 3  # mm
        holeOffsetX = 30  # mm
        holeOffsetY = 40  # mm
        centerHoleDiameter = 10  # mm  # Added center holes

        # Draw base rectangle
        points = [
            adsk.core.Point3D.create(-length/2, -width/2, 0),
            adsk.core.Point3D.create(length/2, -width/2, 0),
            adsk.core.Point3D.create(length/2, width/2, 0),
            adsk.core.Point3D.create(-length/2, width/2, 0)
        ]
        lines = []
        for i in range(4):
            lines.append(sketchLines.addByTwoPoints(points[i], points[(i+1) % 4]))

        # Add wheel cutouts (increased size)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-length/3, -width/2, 0), wheelCutoutDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(length/3, -width/2, 0), wheelCutoutDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-length/3, width/2, 0), wheelCutoutDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(length/3, width/2, 0), wheelCutoutDiameter/2)

        # Add mounting holes
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-holeOffsetX, -holeOffsetY, 0), holeDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(holeOffsetX, -holeOffsetY, 0), holeDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-holeOffsetX, holeOffsetY, 0), holeDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(holeOffsetX, holeOffsetY, 0), holeDiameter/2)

        # Add center holes
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, 0, 0), centerHoleDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, 20, 0), centerHoleDiameter/2)
        sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, -20, 0), centerHoleDiameter/2)

        # Extrude the chassis
        prof = sketch.profiles.item(0)
        extrudes = rootComp.features.extrudeFeatures
        extrudeInput = extrudes.createInput(prof, adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        distance = adsk.core.ValueInput.createByReal(thickness)
        extrudeInput.setDistanceExtent(False, distance)
        extrudes.add(extrudeInput)

        ui.messageBox('Chassis Created Successfully!', 'Success')

    except:
        if ui:
            ui.messageBox('Failed:\n{}'.format(traceback.format_exc()), 'Error')

# Run the script
create_chassis()
